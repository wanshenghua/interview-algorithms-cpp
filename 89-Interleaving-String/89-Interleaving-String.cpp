/*Interleaving String Total Accepted: 6747 Total Submissions: 36207 My Submissions
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
/*Recursive equation
f[i][j] = ((s1[i-1] == s3[i+j-1]) && f[i-1][j]) ||
        ((s2[j-1] == s3[i+j-1]) && f[i][j-1])
*/
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len3 != len1 + len2){
            return false;
        }
        //f[i][j] = true if prefix of length i in s1 and prefix of length j in s2 forms interleaving string s3
        vector<vector<bool> > f(len1 + 1, vector<bool> (len2 + 1, true));
        //i=0,j=0, all empty strings, true
        //boundary condition, empty string
        for(int i = 1; i <= len1; i++){
            if(s1[i - 1] == s3[i - 1]){
                f[i][0] = f[i - 1][0];
            }else{
                f[i][0] = false;
            }
        }
        
        for(int i = 1; i <= len2; i++){
            if(s2[i - 1] == s3[i - 1]){
                f[0][i] = f[0][i - 1];
            }else{
                f[0][i] = false;
            }
        }
        //recursive
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                f[i][j] = ((s1[i - 1] == s3[i + j - 1]) && f[i - 1][j]) || ((s2[j - 1] == s3[i + j -1]) && f[i][j - 1]);
            }
        }
        
        return f[len1][len2];
    }
};