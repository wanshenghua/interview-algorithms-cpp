/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

Key: use modulo and divide 10 to get the least significant digit and do the right shift.
Trivals: deal with overflow, trailing zeros, negative number
*/

class Solution {
public:
    int reverse(int x) {
		int last_digit = 0;
		int res = 0;
		int sign = (x > 0) ? 1 : -1;
		x = abs(x);
		while(x>0){
			last_digit = x % 10;
			x /= 10;
			res = res * 10 + last_digit; //what if overflow here?
		}
		return res * sign;
    }
};

int main()
{

}