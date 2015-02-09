/* Combination Sum II
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
key idea: a COLLECTION of numbers, each number can be used ONCE.
due to COLLECTION, use set to get unique result.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		set<vector<int> > res_set;
		vector<int> comb;
		DFS(candidates, target, res_set, comb, 0);
		vector<vector<int> > res(res_set.begin(), res_set.end());
		return res;
    }
	
	void DFS(vector<int> &candidates, int target, set<vector<int> > &res, vector<int> &comb, int startInd){
		if(target < 0){
			return;
		}else if(target == 0){
			res.insert(comb);
			return;
		}
		
		for(int i = startInd; i < candidates.size(); i++){ //key is startInd
			comb.push_back(candidates[i]);
			DFS(candidates, target - candidates[i], res, comb, i + 1);//only use same or larger candidates
			comb.pop_back();//reset
		}
	}
};