/* Combination Sum
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 

key idea: DFS, sort, start from same or larger candidates
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res;
		vector<int> comb;
		DFS(candidates, target, res, comb, 0);
		return res;
    }
	
	void DFS(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &comb, int startInd){
		if(target < 0){
			return;
		}else if(target == 0){
			res.push_back(comb);
			return;
		}
		
		for(int i = startInd; i < candidates.size(); i++){ //key is startInd
			comb.push_back(candidates[i]);
			DFS(candidates, target - candidates[i], res, comb, i);//only use same or larger candidates
			comb.pop_back();//reset
		}
	}
};