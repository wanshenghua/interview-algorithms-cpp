/* Maximum Subarray
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle

Programming Pearls.

Kadane's Scanning Algorithm O(n) 
	Key: save previous result and use it to find new result
	Trivials: all negative array
Bently's Divide and Conquer O(nlogn)
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max_end_here = 0;
		int max_so_far = 0;
		for(int i = 0; i < n; i++){
			max_end_here = max(0, max_end_here + A[i]);
			max_so_far = max(max_end_here, max_so_far);
		}
		//if all-negative array
 		if(max_so_far == 0){
			//find the maximum number in the array
			int max_num = A[0]; //assert n>0
			for(int i = 1; i < n ; i++){
				max_num = max(A[i], max_num);
			}
			max_so_far = max_num;
		} 
		return max_so_far;
    }
};

void printArray(int A[], int size){
	for(int i = 0; i < size; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}
	
int test(int A[], int size)
{
	Solution sol;
	printArray(A, size);
	int res = sol.maxSubArray(A, size);
	return res;
}

int main()
{
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int B[] = {-1};
	int C[] = {0};
	
	cout << test(A, sizeof(A)/sizeof(int)) << endl;
	cout << test(B, 1) << endl;
	cout << test(C, 1) << endl;
}