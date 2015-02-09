/*Single Number II
 Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

Understanding 
if there is no constraint the memory, a hash table will do in linear time.
if we sort the array, the time complexity could be O(n log n).
if the elements appears twice, we can use XOR and bit vector to achieve linear time complexity. 
        x x x clear	
ones: 0 1 0 1 	=>		0	
twos: 0 0 1 1 	=>		0
        ^   ^
state machine: 00 01 10 00
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int ones = 0; 
		int twos = 0; //if x appears twice, it is memorized and clear existence in ones.
		int threes = 0; //if x appears
		for(int i = 0; i < n; i++){
			twos |= ones & A[i]; //record 2nd occurrences
			ones = ones ^ A[i]; 
			threes = ones & twos; //record of 3rd occurrence 
			//reset records that appears third time
			ones &= ~threes; 
			twos &= ~threes;
		}
		return ones;
    }
};

int main()
{
	Solution sol;
	int A[] = {1,2,3,1,2,3,1,2,3,4};
	cout << sol.singleNumber(A, 10) << endl;
}