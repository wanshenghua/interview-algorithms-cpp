/* Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

idea: n is the number of bits. the sequence shall contain 2^n numbers.

mapping between i to gray code is (i >> 1) ^ i
*/

class Solution {
public:
    vector<int> grayCode(int nBits) {
        vector<int> res;
        int size = 1 << nBits;
        for(int i = 0; i < size; i++){
            res.push_back(bin2gray(i));
        }
        return res;
    }
    
    int bin2gray(int i){
        return (i >> 1) ^ i;
    }
};