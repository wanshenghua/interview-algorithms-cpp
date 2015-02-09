/*Search for a Range
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 

key: binary search for the lower bound and upper bound.
pitfalls: boundary cases when n=0 or 1.
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
/*        if(n == 0){
            return res;
        }
        if(n == 1){
            if(A[0] == target){
                vector<int> res(2, 0);
                return res;
            }
            return res;
        }
*/
        res[1] = searchUpperBound(A, 0, n - 1, target);
        res[0] = searchLowerBound(A, 0, n - 1, target);
        return res;
    }
    
    int searchUpperBound(int A[], int first, int last, int target){
        if(first > last){
            return -1;
        }else if(first == last){
            if(A[first] == target){
                return first;
            }else{
                return -1;
            }
        }
        //last >= first + 1
        int mid = (first + last) / 2; //mid < last
        if(A[mid] == target){
            if(A[mid] == A[mid + 1]){
                return searchUpperBound(A, mid + 1, last, target);           
            }else{
                return mid;
            }
        }else if(A[mid] < target){
            return searchUpperBound(A, mid + 1, last, target);
        }else {
            return searchUpperBound(A, first, mid - 1, target);
        }
    }
    
    int searchLowerBound(int A[], int first, int last, int target){
        if(first > last){
            return -1;
        }else if(first == last){
            if(A[first] == target){
                return first;
            }else{
                return -1;
            }         
        }
         //last >= first + 1
        int mid = (first + last) / 2; //mid < last
        if(A[mid] == target){
            if(A[mid] == A[mid - 1]){
                return searchLowerBound(A, first, mid - 1, target);           
            }else{
                return mid;
            }
        }else if(A[mid] < target){
            return searchLowerBound(A, mid + 1, last, target);
        }else {
            return searchLowerBound(A, first, mid - 1, target);
        }
    }
};