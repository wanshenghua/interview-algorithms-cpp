/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. 

key: count the number of duplicates; the offset is the number of duplicates.
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int same = 0;//number of duplicates
        for(int i = 1; i < n; i++){
            if(A[i] == A[i - 1]){
                same++;
            }
            if(same){
                A[i - same] = A[i]; //same is offset to move A[i] backwards
            }
        }
        return n - same;
    }
};