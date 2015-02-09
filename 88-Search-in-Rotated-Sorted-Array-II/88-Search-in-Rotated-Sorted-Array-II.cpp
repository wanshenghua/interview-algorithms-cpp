/*Search in Rotated Sorted Array II 
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
    
    bool search(int A[], int beg, int end, int target){
        if(beg > end){
            return false;
        }else if(beg == end){
            if(A[beg] == target){
                return true;
            }
            return false;
        }
        
        int mid = (beg + end) / 2;
        while(A[beg] == A[mid] && beg < mid){//key: move mid to lower if A[beg] equals A[mid]
            mid--;
        }  
        //fist + 1 <= last
        if(A[mid] == target){
            return true;
        }
        

        if(A[beg] <= A[mid]){
            if(target > A[mid]){
                return search(A, mid + 1, end, target);
            }else if(target < A[mid] && target >= A[beg]){
                return search(A, beg, mid - 1, target);
            }else if(target <= A[end]){
                return search(A, mid + 1, end, target);
            }
            return false;
        }else{
            if(target >= A[beg]){
                return search(A, beg, mid - 1, target);
            }else if(target > A[mid] && target <= A[end]){
                return search(A, mid + 1, end, target);
            }else if(target < A[mid]){
                return search(A, beg, mid - 1, target);
            }
            return false;
        }
    }
};