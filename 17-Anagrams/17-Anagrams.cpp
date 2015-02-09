/* Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Understanding:
definition of anagram: A word formed by reordering the letters of another word.
the unsaid condition is that there is only one group of anagrams or put all the different groups in one vector.
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string> > key2anagrams; //if input has repetitions, replace vector with set
		for(int i = 0; i < strs.size(); i++){//N
			string key = strs[i];
			sort(key.begin(), key.end()); //MlongM where M is mean word length
			key2anagrams[key].push_back(strs[i]); //total M*NlongN
		}//N * MlogM + M *NlogN, assume M=5 by statistics, ~ NlogN
		vector<string> res;
		for(map<string, vector<string> >::iterator itr = key2anagrams.begin(); 
			itr != key2anagrams.end(); itr++){
			if(itr->second.size() > 1){
				res.insert(res.end(), itr->second.begin(), itr->second.end());
			}
		}
		return res;
	}
};

int main()
{
	string s[] = {"dog", "god"};
	vector<string> strs(s, s + 2);
	Solution sol;
	sol.anagrams(strs);
	return 0;
}