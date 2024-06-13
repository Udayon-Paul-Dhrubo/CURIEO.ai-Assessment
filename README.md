# CURIEO.ai Assessment

## Problem Statement
You can find the detailed problem statement in the [pdf](curieo_swe_assessment.pdf) file.

## Overview
- The task is to implement a function that takes a list of `transactions` and a `query` and returns the maximum number of `previously declined` withdrawals that can be approved after `reordering the deposits` in the query range.

- `Transactions` are represented as : (timestamp, amount, type)
- `Query` is represented as : (start_time, end_time)

## Strategy
- reordering the Deposits only affects the Withdrawals(declined previously) that are in the range of the Query.
- so no need to check transactions up to the Query End time.
- it might be possible that after approving some declined Withdrawals, we have to decline some of the `previously approved `Withdrawals. But that is not a concern for this problem.

## Requirements
- g++ compiler  <br>
or
- Docker

## Directory Structure
```
├── Task#
│   ├── input_generator.cpp
│   ├── solution.cpp
│   ├── input_0.txt     # sample input given in the problem statement
│   ├── run.sh          # to run the input_generator and solution
│   ├── clean.sh        # to clean the input and output files generated
│   ├── Dockerfile      
│   └── docker_run.sh   # to run the code in docker container
│
└── curieo_swe_assessment.pdf # problem statement
```
## Running the solution

### Using Docker
there is `docker_run.sh` file provided in each Task directory to run the code in a docker container.

```bash
cd Task1  # or Task2(depending on the Task you want to run)
./docker_run.sh
```
- if you want to run several times then comment out the `build command` in the `docker_run.sh` file in respective Task directory.
```bash
# Build the docker image
docker build -t task1 .   # or task2(if you are in Task2 directory)
```
- to check the input and output files generated you can check `log` folder in respective Task directory.
- to clean the input and output files `clean.sh` is provided
```bash
./clean.sh
```

### Using g++ compiler
- make sure you have g++ compiler installed in your system.
- go to the respective Task directory
```bash
cd Task1    # or Task2
```
- run the `run.sh` file
```bash
./run.sh
```
- you can check the input and output files generated in the respective Task directory.
- to clean the input and output files `clean.sh` is provided
```bash
./clean.sh
```
  
## Task1
`all the transactions are given and then all the queries are given`.

- solution file : `Task1/solution.cpp`
- input generator : `Task1/input_generator.cpp`

> Note: <br>
> - to generate different inputs everytime you can comment out the line `srand(time(0));` in the main function of `input_generator.cpp` file.
> - sample output given is wrong. the correct output is `1 0 1` <br>
> - `input_5.txt` may take some time to run as it has 10^5 transactions. <br>


## Task2
`transactions and queries are randomly given`.

- solution file : `Task2/solution.cpp`
- input generator : `Task2/input_generator.cpp`


> Note: <br>
> - sample output given is wrong. the correct output is `0 1 0 1` <br>
> - to generate different inputs everytime you can comment the line `srand(time(0));` in the main function of `input_generator.cpp` file.