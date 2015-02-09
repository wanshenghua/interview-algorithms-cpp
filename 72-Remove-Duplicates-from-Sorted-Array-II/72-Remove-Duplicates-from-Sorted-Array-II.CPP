/*Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 

key: when "duplicate" value is discovered, do not move it, only increase the offset

this is a template, just replace 2 to another number.
the origin version was a special case.
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2){
            return n;
        }
        
        int count = 1; //number of occurrences of a value
        int offset = 0;
        int prev_val = A[0]; //previous value
        for(int i = 1; i < n; i++){
            if(A[i] == prev_val){
                count++;
                if(count > 2){
                    offset++;//key: "duplicate" value, do not move it, only increase the offset
                }else{//still old value
                    A[i - offset] = A[i];
                }
            }else{//a new value
                prev_val = A[i];
                count = 1;//update
                A[i - offset] = A[i];      
            }
        }
        return n - offset;
    }
};