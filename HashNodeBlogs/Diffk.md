## Diffk- Interviewbit

Hi Devs, Happy Coding 
I am planning to revise Data Structure and Algorithms Concepts so I will be sharing my approach as well as a full solution for problems I solve. This is my first attempt at writing a dev blog, yeah I am a bit nervous. Hope you like it and Your valuable feedback and contributions are always welcome.

Today I am going to solve a coding problem [Diffk](https://www.interviewbit.com/problems/diffk/) which is based on the Two Pointer concept. 

> Problem Statement - Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

**Time and Space Complexity Constraint**   
1. Try doing this in less than linear space complexity.

**Example** 

```
Input :
  A : [1 3 5] 
  k : 4
Output : YES
Explanation : as 5 - 1 = 4
```

**Brute Force Approach -** we use two loop for two indices i,j  and iterate if we find any A[j]-A[i] = k and i!=j then return 1 else 0.

```
int diffPossible(vector<int> &A, int k) {
  int N= A.size();
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[j] - A[i] > k) break; // No need check forward because Array is sorted so the difference is going to increase even further because A[I] is going to increase or remain same.
      if (A[j] - A[i] == k) return 1; 
    }
  }
  return 0;
}
```
The Time Complexity of this approach is O(N*N). 

**Observation**
Let's check the above approach when we have `i = I` and find `j=J` ,`Diff_1 =(A[J-1]-A[I])` such that `Diff_1 <k` and `A[J]-A[I] >k`

**Observation 1 -** This means that for `i =I` and `j> J` we are not going to find our solution because `A[j]` will be increasing(Array is sorted) so will `A[j]-A[I]`.
**Observation 2 -** when `i` increase then `A[i]` will increase too then `A[J]- A[i]` will decrease so till `j =J-1` our `A[j] -A[i]` will be less than `Diff_1` which is also less than `k`( Observation 1 ) So we will not find our solution till `j =J-1`. So Efficient Approach will be when we don’t start `j` every time with `I+1` but start with j=J.

**New Approach Code (Time Complexity:  O(n))**
```
int diffPossible(vector<int> &A, int k) {
    int N = A.size();
    int j = 0; 
    for (int i = 0; i < N; i++) {
        j = max(j, i+1);
        while (j < N && (A[j] - A[i] < B)) {
            j += 1;
        }
        if (A[j] - A[i] == B) return 1;
    }
    return 0;
}
```

[Github Solution Link](https://github.com/vpsinghg/DSA/blob/master/InterviewBit/Two-Pointer/Diffk.cpp)