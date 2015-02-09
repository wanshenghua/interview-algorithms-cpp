/* Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

idea: use a table
key: 1*10^n,4*10^n,5*10^n,9*10^n is the key, then use greedy algorithm for make the change of money.
*/

class Solution {
public:
    string intToRoman(int num) {
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[]      = {1000, 900, 500, 400,  100,  90,  50,   40,   10,  9,    5,   4,    1};
        
        string res;
        for(int i = 0; num !=0; i++){
            while(num >= value[i]){
                num -= value[i];
                res += symbols[i];
            }
        }
        return res;
    }
};