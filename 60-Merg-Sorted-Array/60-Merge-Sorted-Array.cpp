/*Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

idea: merge from the tail of the arrays.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(!n){
            return ;
        }
 /* unnecessary, i < 0 will check this
		if(!m){
            for(int i = 0; i < n; i++){
                A[i] = B[i];
            }
            return ;
        }
*/
        
        int i = m - 1;
        int j = n - 1;
        for(int k = m + n - 1; k >= 0; k--){
            if(i >=0 && j >= 0){
                if(A[i] < B[j]){//keep largest
                    A[k] = B[j];
                    j--;
                }else{
                    A[k] = A[i];
                    i--;
                }
            }else if(i < 0){ // A is running out
                A[k] = B[j];
                j--;
            }else if(j < 0){// B is running out
			/* unnecessary, the rest of A stands still
				A[k] = A[i];
                i--;
			*/
			}
        }
        return;
    }
};