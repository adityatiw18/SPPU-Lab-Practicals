# Design and Analysis of Algorithms (DAA) Practicals

All programs are written in C++ and correspond to the five DAA assignments.

## Programs

| Assignment | File | Description |
|---|---|---|
| A1 | `A1_Fibonacci.cpp` | Recursive and iterative Fibonacci |
| A2 | `A2_Huffman_Encoding.cpp` | Huffman coding using a greedy min-heap |
| A3 | `A3_01_Knapsack_DP.cpp` | 0-1 Knapsack using dynamic programming |
| A4 | `A4_NQueens_First_Queen_Placed.cpp` | N-Queens backtracking with a pre-placed queen |
| A5 | `A5_QuickSort_Deterministic_Randomized.cpp` | Deterministic and randomized Quick Sort |

## Compile and run

Use a C++17 compiler:

```bash
g++ -std=c++17 A1_Fibonacci.cpp -o fibonacci
./fibonacci
```

Replace the source filename and executable name for the other programs.

## Time and space complexity

| Program | Time complexity | Auxiliary space |
|---|---|---|
| Recursive Fibonacci | O(2^n) | O(n) recursion stack |
| Iterative Fibonacci | O(n) | O(1) |
| Huffman construction | O(n log n) | O(n) |
| 0-1 Knapsack DP | O(nW) | O(nW) |
| N-Queens backtracking | O(N!) upper bound | O(N²) board + O(N) recursion |
| Quick Sort | Average O(n log n), worst O(n²) | Average O(log n), worst O(n) recursion |

For Knapsack, `W` denotes capacity. For Huffman, `n` denotes the number of distinct characters.

## Notes

- A1 restricts `n` to 0 through 45 so recursive computation remains practical and results fit in `long long`.
- A2 expects distinct characters and positive frequencies.
- A3 uses the dynamic programming option for the 0-1 Knapsack assignment.
- A4 accepts the already-placed queen's row and column as 1-based input.
- A5 uses the last element as the deterministic pivot and a randomly selected pivot for randomized Quick Sort.
