#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0 || s[0] == '0'){ //key: check s[0] = '0' refuse heading 0's
            return 0;
        }
        
        vector<int> ways(len + 1, 0);
        ways[0] = 1; //key: initial conditions:
        ways[1] = 1;
        
        for(int i = 1; i < len; i++){
            if(isValid2WayCode(s[i - 1], s[i])){
                ways[i + 1] = ways[i] + ways[i - 1]; //interpreted as : ..., s[i] or ..., s[i-1]s[i]
            }else if(isTenOrTwenty(s[i-1], s[i])){
                ways[i + 1] = ways[i - 1]; //interpreted as: ..., s[i-1]s[i]
            }else if(isValid1BitCode(s[i])){
                ways[i + 1] = ways[i]; //interpreted as ..., s[i] 
            }else{
                return 0; //encoutered invalid code
            }
        }
        return ways[len];
    }
    //check if "ab" is a valid 2-bit code, including 10,11->19, 20, 21->26
    bool isValid2WayCode(char a, char b){
        if(a == '1' && b != '0'){
            return true;
        }else if(a == '2' && (b >= '1' && b <= '6')){
            return true;
        }
        return false;
    }
    
    bool isTenOrTwenty(char a, char b){
        if((a == '1' && b == '0') || (a == '2' && b == '0')){
            return true;
        }
        return false;
    }
    bool isValid1BitCode(char c){
        if(c <= '9' && c >= '1'){
            return true;
        }
        return false;
    }
    
};

int main()
{
    Solution sol;
    cout << sol.numDecodings(string("1")) << endl;
    cout << sol.numDecodings(string("10")) << endl;
    cout << sol.numDecodings(string("11")) << endl;
    cout << sol.numDecodings(string("01")) << endl;
    return 0;
}