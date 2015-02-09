/* Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 

key: reuse the previous row
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        if(!rowIndex){
            return res;
        }
        
        for(int i = 1; i <= rowIndex; i++){
            int ncols = i + 1;//i-th row has i+1 items
            int save_old_res_j_minus_1 = 1;
            for(int j = 1; j < ncols - 1; j++){
                int temp = res[j]; //will be used next iteration
                res[j] += save_old_res_j_minus_1;
                save_old_res_j_minus_1 = temp;
            }
        }
        return res;
    }
};