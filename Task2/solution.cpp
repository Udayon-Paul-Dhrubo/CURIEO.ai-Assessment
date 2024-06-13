#include <bits/stdc++.h>
using namespace std;

struct Transaction
{
    int timestamp;
    string type;
    int amount;
};

int InitialReserve = INT_MIN;

vector<Transaction> transactions;

unordered_set<int> declinedWithdrawals;

int simulateTransactions(vector<Transaction> &transactions, int fromIndex, int currReserve)
{
    for (int i = fromIndex; i < transactions.size(); i++)
    {
        if (transactions[i].type == "Deposit")
            currReserve += transactions[i].amount;

        else if (transactions[i].type == "Withdraw")
        {
            if (currReserve >= transactions[i].amount)
                currReserve -= transactions[i].amount;

            else
                declinedWithdrawals.insert(transactions[i].timestamp);
        }
    }

    return currReserve;
}

int countAdditionalProcessable(int start_time, int end_time)
{
    vector<Transaction> inRange_Withdrawals;
    int reserve = InitialReserve;

    for (const auto &txn : transactions)
    {
        if (txn.timestamp < start_time)
        {
            if (txn.type == "Deposit")
                reserve += txn.amount;

            else if (txn.type == "Withdraw" && reserve >= txn.amount)
                reserve -= txn.amount;
        }

        else if (txn.timestamp >= start_time && txn.timestamp < end_time)
        {
            if (txn.type == "Deposit")
                reserve += txn.amount;

            else if (txn.type == "Withdraw")
                inRange_Withdrawals.push_back(txn);
        }

        else
            break;
    }

    int additionalProcessable = 0;

    for (const auto &txn : inRange_Withdrawals)
    {
        if (reserve >= txn.amount)
        {
            reserve -= txn.amount;

            if (declinedWithdrawals.find(txn.timestamp) != declinedWithdrawals.end())
                additionalProcessable++;
        }
    }

    return additionalProcessable;
}

void solve(int file_number)
{
    string inputFilename = "input_" + to_string(file_number) + ".txt";
    string outputFileName = "output_" + to_string(file_number) + ".txt";

    // resetting the global variables
    InitialReserve = INT_MIN;
    transactions.clear();
    declinedWithdrawals.clear();

    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFileName);

    int num_transactions, num_queries;

    string line;

    bool firstLine = true;
    int lastTransaction_index = 0;
    int currReserve = 0;

    while (getline(inputFile, line))
    {
        if (line.empty())
            break;

        stringstream ss(line);

        if (firstLine)
        {
            ss >> InitialReserve >> num_transactions >> num_queries;

            currReserve = InitialReserve;

            firstLine = false;
            continue;
        }

        string type;
        ss >> type;

        if (type == "Query")
        {
            int start_time, end_time;
            ss >> start_time >> end_time;

            currReserve = simulateTransactions(transactions, lastTransaction_index, currReserve);
            lastTransaction_index = transactions.size();

            int ans = countAdditionalProcessable(start_time, end_time);

            // cout << ans << endl;

            outputFile << ans << endl;
        }

        else
        {
            Transaction txn;
            txn.timestamp = stoi(type);

            ss >> txn.type >> txn.amount;

            transactions.push_back(txn);
        }
    }

    inputFile.close();
    outputFile.close();
}

int main()
{

    int choice;
    cout << "0 - to run a specific test case \n1 - to run all test cases \n\tEnter Choice : ";
    cin >> choice;

    if (choice == 0)
    {
        int file_number;

        cout << "\tEnter the input file number : ";
        cin >> file_number;

        cout << "Running test case - " << file_number << "...\n";

        solve(file_number);

        cout << "Output written to output_" << file_number << ".txt" << endl;
    }

    else if (choice == 1)
    {

        for (int i = 0; i <= 5; i++)
        {
            cout << "Running test case - " << i << "...\n";

            solve(i);

            cout << "Output written to output_" << i << ".txt" << endl;
        }
    }

    cout << "Task2 Completed" << endl;

    return 0;
}