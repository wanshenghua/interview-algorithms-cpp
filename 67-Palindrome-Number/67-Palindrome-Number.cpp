/*Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(0 > x){
            return false; //negative number is not a palindrome
        }
        int base = 1; //get the order of 10
        while(10 <= x / base){ //increase base until x/base is less than 10
            base *= 10;
        }
        int lsb = 0, msb = 0;
        while(10 <= x){//until x is 1-digit
            lsb = x % 10;
            msb = x / base;
            if(lsb != msb){
                return false;
            }
            x = (x % base) / 10; //remove lsb and msb
            base /= 100; // since 2 digits are removed from x.
        }
        return true;
    }
};