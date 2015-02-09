/*Remove Element
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

key: the offset to move non-duplicate is A[i-numDup] = A[i];
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int numDup = 0; //number of duplicates is the offset to move each item.
        
        for(int i = 0; i < n; i++){
            if(A[i] == elem){
                ++numDup;
            }else{//only move non-duplicate items
               A[i - numDup] = A[i];
            }
        }
        return n - numDup;
    }
};