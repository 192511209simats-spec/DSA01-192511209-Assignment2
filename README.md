# DSA01 – Assignment 2 (CO2)

C++17 source code for Questions 1–7.

## Requirements
- GNU g++ compiler with C++17 support
- A terminal / command prompt

## Compile and run
From the repository root, compile each program separately:

```bash
g++ -std=c++17 -Wall -Wextra Q1/q1.cpp -o q1
./q1

g++ -std=c++17 -Wall -Wextra Q2/q2.cpp -o q2
./q2

g++ -std=c++17 -Wall -Wextra Q3/q3.cpp -o q3
./q3

g++ -std=c++17 -Wall -Wextra Q4/q4.cpp -o q4
./q4

g++ -std=c++17 -Wall -Wextra Q5/q5.cpp -o q5
./q5

g++ -std=c++17 -Wall -Wextra Q6/q6.cpp -o q6
./q6

g++ -std=c++17 -O2 -Wall -Wextra Q7/q7.cpp -o q7
./q7
```

On Windows PowerShell, run the executables as `.\q1.exe`, `.\q2.exe`, etc.
The compilation commands can use `-o q1.exe` if preferred.

## Additional experiments

### Q2 compiler warning
Compile with warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra -Wreturn-local-addr Q2/q2.cpp -o q2
```

`dangerousLocalReference()` intentionally returns a reference to a local variable.
It is not called. The compiler may warn about this; exact warning wording depends on
compiler version.

### Q6 inline timing
Compile and run the benchmark with both optimisation levels:

```bash
g++ -std=c++17 -O0 Q6/q6_benchmark.cpp -o q6_O0
./q6_O0

g++ -std=c++17 -O2 Q6/q6_benchmark.cpp -o q6_O2
./q6_O2
```

Record the timings produced on your own computer. Do not copy timings from another system.

### Q7 redesign comparison
`Q7/q7.cpp` compares a shifting array with a circular buffer using the same
one-million input sequence. It also checks that the retained oldest and newest
values match. Record your actual timing output.

## Suggested evidence to add
Create an `evidence/` folder and save your own terminal screenshots after running
each program. Include compiler warning output for Q2 and timing output for Q6
and Q7. Do not create or submit fabricated screenshots or timing values.

## Important assignment notes
- Write predictions before running the relevant predict-the-output programs.
- Explain the results in your own words in the report.
- Q7 uses the Q4 transaction-history problem as its redesign case study.
- Q4 uses a fixed array of ten entries and shifts when full, as requested.
- Q5's first four tickets demonstrate the required capacity-3 allocation.
  Later function calls demonstrate that the static count persists.
