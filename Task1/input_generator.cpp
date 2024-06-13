#include <bits/stdc++.h>
using namespace std;

struct Transaction
{
    int timestamp;
    string type;
    int amount;
};

void generateTestFile(const string &filename, int numTransactions, int numQueries)
{
    ofstream outputFile(filename);

    int initialReserve = rand() % 10000 + 1000;

    outputFile << initialReserve << " " << numTransactions << " " << numQueries << endl;

    int currentTime = 1000;
    for (int i = 0; i < numTransactions; ++i)
    {
        Transaction txn;

        txn.timestamp = currentTime;

        txn.type = (rand() % 2 == 0) ? "Deposit" : "Withdraw";

        txn.amount = rand() % 10000 + 1;

        outputFile << txn.timestamp << " " << txn.type << " " << txn.amount << endl;

        currentTime += rand() % 100 + 1; // Ensure unique and increasing timestamps
    }

    for (int i = 0; i < numQueries; ++i)
    {
        int startTime = rand() % currentTime;
        int endTime = rand() % currentTime;

        if (startTime > endTime)
            swap(startTime, endTime);

        outputFile << "Query " << startTime << " " << endTime << endl;
    }

    outputFile.close();
}

int main()
{
    srand(time(0));

    int numTransactions = 10;
    int numQueries = 3;

    // Generate 5 test files with increasing size
    for (int i = 1; i <= 5; i++)
    {

        if (i > 1)
        {
            numTransactions *= 10;
            numQueries *= 10;
        }

        string filename = "input_" + to_string(i) + ".txt";

        generateTestFile(filename, numTransactions, numQueries);
    }
    cout << "Test files generated successfully." << endl;

    return 0;
}
