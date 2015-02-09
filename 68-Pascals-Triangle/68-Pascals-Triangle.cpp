/* Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(!numRows){
            return res;
        }
        vector<int> first_row(1, 1); //initializer
        res.push_back(first_row);
        
        for(int i = 1; i < numRows; i++){
            vector<int> row(res[i - 1].size() + 1, 1); //initialize, size, boundary value=1
            for(int j = 1; j < row.size() - 1; j++){ //exclude first and last boundary items
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};