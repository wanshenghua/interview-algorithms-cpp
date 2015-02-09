/* Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

***handle with care 
key: use select k-th element in two sorted array
if (m+n) is even, median is (m+n)/2 indexed => (m+n)/2 + 1 -th
otherwise if (m+n) is odd, median is (m+n)/2-1, (m+n)/2 indexed => (m+n)/2, (m+n)/2+1 -th

Note: k-th => index is k-1

(a_0, a_1, ..., a_m/2-1), (a_m/2, ..., a_m-1)
   section 1               section 2
(b_0, b_1, ..., b_n/2-1), (b_n/2, ..., b_n-1)
   section 3               section 4
in non-decreasing order

   
see middle elements a_m/2 and b_n/2
if (m/2 + n/2 + 1) >= k, the target should not be in section 2 or 4, but must be in 1 or 3 plus the left one in  2/4
otherwise (m/2 + n/2 + 1) <k, the target should not be in section 1 or 3

if a_m/2 >= b_n/2, section 2 is larger than section 1 and 3, section 3 is less than section 2 and 4
   if (m/2 + n/2) > k, the target definitely should not be in section 2, dropt it.
   else the target should not be in section 3.
if a_m/2 < b_n/2, section 1 is les//ds than section 2 and 4, section 4 is larger than section 1 and 3
   if (m/2 + n/2) > k, the target definitely should not be in section 4
   else the target should not be in section 1

PITFALL: make sure each time remove at least 1 item.

difficulty: 5-star

details:
if a_m/2 >= b_n/2, 
  (a_0, ..., a_m/2-1) <= a_m/2, ..., a_m-1
                        ||
                         V
  (b_0, ..., b_n/2-1, b_n/2) <= b_n/2+1, ..., b_n-1
  if m/2 + n/2 + 1 == k, a_m/2 is at least k+1 -th smallest, kick out a_m/2,...,a_m-1 is OK.
  if m/2 + n/2 + 1 > k, a_m/2 is at least k+2 -th smallest, same with above.
  if m/2 + n/2 + 1 < k, b_n/2 is at most k-1 smallest, kickout b_0, ..., b_n/2 is OK.
  
*/

#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if( (m + n) % 2){//odd
            return findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1);
        }
        return (findKthSortedArrays(A, m, B, n, (m + n) / 2) + findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
    }
    
	void printArray(int A[], int m, const string &header=""){
		cout << header;
		for(int i = 0; i < m; i++){
			cout << A[i]  << " ";
		}
		cout << endl;
	}

    int findKthSortedArrays(int A[], int m, int B[], int n, int k){
//		cout << k << endl;
//		printArray(A, m, "A = ");
//		printArray(B, n, "B = ");

		if(m <= 0){ //A is out
			return B[k - 1];
		}
		if(n <= 0){ //B is out
			return A[k - 1];
		}
		//A, B at least of length 1
		if(k == 1){
			return std::min(A[0], B[0]);
		}
		if(A[m/2] >= B[n/2]){
			if( m/2 + 1 + n/2 >= k){
				return findKthSortedArrays(A, m/2, B, n, k); // m/2 could not guarantee remove at least 1 item
			}else{
				return findKthSortedArrays(A, m, B + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1)); //n/2+1>=1, remove at lease one 1 item
			}
		}else{
			if( 1 + m/2 + n/2 >= k){
				return findKthSortedArrays(A, m, B, n/2, k);
			}else{
				return findKthSortedArrays(A + m/2 + 1, m - (m/2 + 1), B, n, k - (m/2 + 1));
			}
		}
    }
};
int main()
{
    int A[] = {1, 1};
    int B[] = {1, 1};
   Solution sol;
   cout << sol.findMedianSortedArrays(A, 2, B, 2) << endl;
   
   return 0;
}
