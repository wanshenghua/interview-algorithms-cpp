/*Divide Two Integers
Divide two integers without using multiplication, division and mod operator. 
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        
        long long ret = 0;
        while(a >= b){ //key: loop while the reminder of a - 2^n * b is smaller than 2^(n+1) * b 
            long long c = b;
            for(int i = 0; a >= c; i++, c <<= 1){ //keep a -= b, 2b, 4b,...
                a -= c;
                ret += 1 << i;
            }
        }
    	return ((dividend^divisor)>>31) ? -ret : ret; //check sign
    }
};

