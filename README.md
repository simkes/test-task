# test-task

File "solution.cpp" contains the implementation of the algorithm, written in C++ language.
Tests can be found in "tests" folder.

Program reads input from std::cin and writes output in std::cout.

Input format:

Important: array `q[]` with questions is used only for testing, solution of the task does not
depend on the array of questions (as it is not used in solving learnedTopics function).

```
int N - number of hours we have to prepare
int M - number of topics
int[] t - t[i] = number of hours required by i topic
int[] k - k[i] = number of questions in i topic
int L - number of questions that will be asked
int[] q - randomly generated array, where q[i] = index of topic of question i, 
(each question appears with an equal probability)
```

Test cases:

```
1.

Input:
4
3
4 1 1
5 2 2
2
0 0

Output:
Mark out of 1 is 1.000000.
(Learned topics : [0])

```
```
2.

Input:
10
5
4 1 1 6 3
3 2 2 5 2
3
0 3 3

Output:
Mark out of 1 is 0.666667.
(Learned topics : [1,3,2])
```
```
3.

Input:
20
10
2 4 5 2 3 5 6 2 1 5
5 3 2 5 4 1 5 7 8 9
17
9 3 9 7 6 0 8 7 9 5 1 0 0 8 8 0 9

Output:
Mark out of 1 is 0.882353.
(Learned topics : [0,8,1,9,7,4,3])
```
```
4.

Input:
30
20
2 5 8 3 3 7 9 10 1 7 10 2 4 4 9 8 10 5 5 5
15 15 1 9 15 12 4 9 3 12 6 7 1 16 8 9 4 2 9 9
18
13 1 13 5 7 6 11 18 13 1 5 16 7 13 12 7 6 1

Output:
Mark out of 1 is 0.500000.
(Learned topics : [0,3,1,18,11,4,19,13,8])
```