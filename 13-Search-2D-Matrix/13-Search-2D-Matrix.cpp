/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		bool found = false;
		search2DMat(matrix, 0, cols - 1, target, found);
		return found;
    }
	
	void search2DMat(vector<vector<int> > &mat, int i, int j, int target, bool &found){
		if(i >= mat.size() || j < 0){
			return;
		}
		
		if(mat[i][j] < target){
			search2DMat(mat, i + 1, j, target, found);
		}else if(mat[i][j] > target){
			search2DMat(mat, i, j - 1, target, found);
		}else{
			found = true;
			return ;
		}
	}
};