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

void simulateTransactions(vector<Transaction> &transactions)
{
    int reserve = InitialReserve;

    for (const auto &txn : transactions)
    {
        if (txn.type == "Deposit")
            reserve += txn.amount;

        else if (txn.type == "Withdraw")
        {
            if (reserve >= txn.amount)
                reserve -= txn.amount;

            else
                declinedWithdrawals.insert(txn.timestamp);
        }
    }
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
    string inputFileName = "input_" + to_string(file_number) + ".txt";
    string outputFileName = "output_" + to_string(file_number) + ".txt";

    // resetting the global variables
    InitialReserve = INT_MIN;
    transactions.clear();
    declinedWithdrawals.clear();

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    int num_transactions, num_queries;

    inputFile >> InitialReserve >> num_transactions >> num_queries;

    for (int i = 0; i < num_transactions; i++)
    {
        Transaction txn;
        inputFile >> txn.timestamp >> txn.type >> txn.amount;
        transactions.push_back(txn);
    }

    simulateTransactions(transactions);

    for (int i = 0; i < num_queries; i++)
    {
        string temp;
        int start_time, end_time;

        inputFile >> temp >> start_time >> end_time;

        int ans = countAdditionalProcessable(start_time, end_time);

        // cout << ans << endl;

        outputFile << ans << endl;
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

    cout << "Task1 Completed" << endl;
    return 0;
}