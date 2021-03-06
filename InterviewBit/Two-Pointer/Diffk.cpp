/*
    Problem Title  - Diffk
    Platform - InterviewBit
    Problem Link - https://www.interviewbit.com/problems/diffk/
    Based On Concept - Two Pointers
    Data Structure  - Array
    Asked in Company - Facebook
    Difficulty Level - Medium

    Problem Statement- Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

    Example:
        Input :

            A : [1 3 5] 
            k : 4
        Output : YES

        as 5 - 1 = 4

    Return 0 / 1 ( 0 for false, 1 for true ) for this problem

    Try doing this in less than linear space complexity.

*/

/* Full Solution Blog 
    HashNode - https://vikramsinghgurjar.hashnode.dev/diffk-interviewbit-two-pointer-approach
    Dev - https://dev.to/vpsinghg/diffk-interviewbit-21jj
*/

// Brute Force Approach
int Solution::diffPossible(vector<int> &A, int B) {
    int N= A.size();
    for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
        if (A[j] - A[i] > B) break; // No need check forward because Array is sorted so the difference is going to increase even further because A[I] is going to increase or remain same.
        if (A[j] - A[i] == B) return true; 
    }
    }
    return false
}

// Efficient Approaches
int Solution::diffPossible(vector<int> &A, int B) {
    int N = A.size();
    if(N<=1){
        return 0;
    }
    int left = 0;
    int right = 1;

    while(left<=right and right<N){
        if(A[right]-A[left]==B){
            if( right!=left){
                return 1;
            }
            else
            {
                right++;
            }
        }
        else if(A[right]-A[left]>B){
            left++;
        }
        else{
            right++;
        }
    }
    return 0;

}

int Solution::diffPossible(vector<int> &A, int B) {

    int N = A.size();
    int j = 0; 
    for (int i = 0; i < N; i++) {
        j = max(j, i+1);
        while (j < N && (A[j] - A[i] < B)) {
            j += 1;
        }
        if (A[j] - A[i] == B) return true;
    }
    return false;
}