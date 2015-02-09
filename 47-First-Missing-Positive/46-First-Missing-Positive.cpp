/* First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 

ideas: make the array a hash table.
first loop: change negative numbers to a out of range positive number.
second loop: mark the seen number by making the corresponding position negative value
third loop: find a positive number in the array, return index + 1
pitfall: if there is not positive number in 3rd loop, return n+1.
*/

class Solution {
public:    
    int firstMissingPositive(int A[], int n) {
        int outOfRange = n + 2;
        
        for(int i = 0; i < n; i++){
            if(A[i] <= 0){
                A[i] = outOfRange;//change elements that is out of range to n+2, which does not exist in the range.
            }
        }
        
        for(int i = 0; i < n; i++){
            int norm = abs(A[i]);
            if(norm <= n){
                int index = norm - 1;
                A[index] = -abs(A[index]);
            }
        }
        for(int i = 0; i < n; i++){
            if(A[i] > 0){
                return i + 1;
            }
        }
        return n + 1;
    }
};