/*Roman to Integer
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

key: if curren value is less than next value, substract current value from the result.
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> sym2val;
        sym2val.insert(make_pair('M', 1000));
        sym2val.insert(make_pair('D', 500));
        sym2val.insert(make_pair('C', 100));
        sym2val.insert(make_pair('L', 50));
        sym2val.insert(make_pair('X', 10));
        sym2val.insert(make_pair('V', 5));
        sym2val.insert(make_pair('I', 1));
        
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n - 1; i++){
            if(sym2val[s[i]] >= sym2val[s[i+1]]){// current value is larger or equal than the next value
                res += sym2val[s[i]];
            }else{//key: current value is less than the next value;
                res -= sym2val[s[i]];
            }
        }
        res += sym2val[s[n - 1]];
        return res;
    }
};