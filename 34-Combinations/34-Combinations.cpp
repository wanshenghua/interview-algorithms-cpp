/* Combinations

 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
		vector<int> comb;
		DFS(n, k, 1, res, comb);
		return res;
    }
	
	void DFS(int max, int target_level, int level, vector<vector<int> > &res, vector<int> &comb){
		if(comb.size() == target_level){
			res.push_back(comb);
			return;
		}
		for(int i = level; i <= max; i++){
			comb.push_back(i);
			DFS(max, target_level, i + 1, res, comb);
			comb.pop_back();
		}
	}
};