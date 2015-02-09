/* Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

key: divide the possibilities: mid on left/right, then divide the range into three intervals plus out of boundary.
pitfalls: check whether the target is out of the boundary.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
    
    int search(int A[], int beg, int end, int target){
        if(beg > end){
            return -1;
        }else if(beg == end){
            if(A[beg] == target){
                return beg;
            }
            return -1;
        }
        
        int mid = (beg + end) / 2;
        //fist + 1 <= last
        if(A[mid] == target){
            return mid;
        }
        if(A[beg] <= A[mid]){
            if(target > A[mid]){
                return search(A, mid + 1, end, target);
            }else if(target < A[mid] && target >= A[beg]){
                return search(A, beg, mid - 1, target);
            }else if(target <= A[end]){
                return search(A, mid + 1, end, target);
            }
            return -1;
        }else{
            if(target >= A[beg]){
                return search(A, beg, mid - 1, target);
            }else if(target > A[mid] && target <= A[end]){
                return search(A, mid + 1, end, target);
            }else if(target < A[mid]){
                return search(A, beg, mid - 1, target);
            }
            return -1;
        }
    }
};