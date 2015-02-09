/*

Distinct Subsequences
Total Accepted: 5925 Total Submissions: 24860

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Understanding, given T of size m, S of size n, the number of distinct subsequences of T in S is
A[m][n]
when m=0, A[0][0,1...n] = 1, T=empty string
when n=0, A[0,1...m] = 0, S=empty string
The matrix is like
1 1 ... 1
0
.
.
0
DP always acts like this, the boundary of the matrix is trivial case and needs to be filled first.
if the last char of T is not equal to last one of S, i.e. T[m-1]!=S[n-1], the number of distinct subsequences is simple A[m][n-1]
   A[m][n] = A[m][n-1]
otherwise, if they are the same char, we have got some new subsequences of T in S, whose length is larger,
then A[m][n] = A{m][n-1] + A[m-1][n-1]
*/

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.size();
        int n = S.size();
        vector<vector<int> > A(m + 1, vector<int>(n + 1, 0)); // key: size is m+1, n+1
        
        //boundary condition
        for(int i = 0; i < n; i++){
            A[0][i] = 1; //initial boundary condition
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(T[i - 1] == S[j - 1]){
                    A[i][j] = A[i][j - 1] + A[i - 1][j - 1];
                }else{
                    A[i][j] = A[i][j - 1];
                }
            }
        }
        return A[m][n];
    }
};