/* Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Ideas: a typical DP problem.
two strings S[0...m-1], T[0...n-1]
A[m][n] is the edit distance between S and T.

if S[m-1]==T[n-1], ending with same char,
   A[m][n] = A[m-1][n-1]
otherwise, we might have three choices: insert, delete, replace, and find the minimum of the three potential distances.
	(1) S[0...m-1] --(insert T[n-1] after S[m-1])--> S[0...m-1]T[n-1], distance(S[0...m-1]T[n-1], T[0...n-2]T[n-1])=A[m][n-1], A[m][n]=A[m][n-1]+1 (key)
	 or S[0...m-1] --(insert T[n-1] before S[m-1])--> S[0...m-2]T[n-1][m-1], distance(S[0...m-2]T[n-1]S[m-1], T[0...n-2]T[n-1])=A[m-1][n-1], A[m][n]=A[m-1][n-1]+1 (key)
	(2) S[0...m-1] --(replaces S[m-1] to T[n-1])--> S[0...m-2]T[n-1], distance(S[0...m-2]T[n-1], T[0...m-2]T[n-1])=A[m-1][n-1] => A[m][n] = A[m-1][n-1]+1
	(3) S[0...m-1] --(delete S[m-1])--> S[0...m-2], distance(S[0...m-2], T[0...n-1])=A[m-1][n] => A[m][n] = A[m-1][n] + 1

boundary condition
if m=0, S=empty string, A[0][0...n]=0...n 
if n=0, T=empty string, A[0...m][0]=0...m
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int> > A(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            A[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            A[0][i] = i;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    A[i][j] = A[i - 1][j - 1];
                }else{
                    A[i][j] = std::min(A[i-1][j-1] + 1, std::min(A[i][j - 1] + 1, A[i - 1][j] + 1));
                }
            }
        }
        return A[m][n];
    }
};