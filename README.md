# CURIEO.ai Assessment

## Problem Statement
You can find the detailed problem statement in the [problem_statement.pdf](problem_statement.pdf) file.

## Overview
- The task is to implement a function that takes a list of `transactions` and a `query` and returns the maximum number of `previously declined` withdrawals that can be approved after `reordering the deposits` in the query range.

- `Transactions` are represented as : (timestamp, amount, type)
- `Query` is represented as : (start_time, end_time)

## Strategy
- reordering the Deposits only affects the Withdrawals(declined previously) that are in the range of the Query.
- so no need to check transactions up to the Query End time.
- it might be possible that after approving some declined Withdrawals, we have to decline some of the `previously approved `Withdrawals. But that is not a concern for this problem.

## Requirements
- g++ compiler <br>
  
if not installed, you can install it using:
```bash
sudo apt-get update
sudo apt-get install g++
g++ --version
```

  
## Task1
`all the transactions are given and then all the queries are given`.

- solution file : `Task1/solution.cpp`
- input generator : `Task1/input_generator.cpp`

to run the input generator:
```bash
cd Task1
g++ input_generator.cpp -o input_generator
```
to run the solution:
```bash
g++ solution.cpp -o solution
```
- to run both `run.sh` is provided
```bash
./run.sh
```
- to clean the input and output files `clean.sh` is provided
```bash
./clean.sh
```
> Note: <br>
> - `input_0.txt` is the sample input given in the problem statement. <br>
> - sample output given is wrong. the correct output is `1 0 1` <br>
> - `input_5.txt` may take some time to run as it has 10^5 transactions. <br>


## Task2
`transactions and queries are randomly given`.

- solution file : `Task2/solution.cpp`
- input generator : `Task2/input_generator.cpp`

to run the input generator:
```bash
cd Task2
g++ input_generator.cpp -o input_generator
```
to run the solution:
```bash
g++ solution.cpp -o solution
```
- to run both `run.sh` is provided
```bash
./run.sh
```
- to clean the input and output files `clean.sh` is provided
```bash
./clean.sh
```

> Note: <br>
> - `input_0.txt` is the sample input given in the problem statement. <br>
> - sample output given is wrong. the correct output is `0 1 0 1` <br>