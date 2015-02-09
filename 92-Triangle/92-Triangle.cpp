/*Triangle 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
//f[i][j] is the min path sum
//f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
//boundary is bottom row.
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int nRows = triangle.size();        
        if(nRows == 0){
            return 0;
        }
        
        //backwards from the 2nd last row, and resue this row
        for(int i = nRows - 2; i >= 0; i--){
            for(int j = 0; j < i + 1; j++){
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};