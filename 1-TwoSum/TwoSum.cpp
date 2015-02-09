/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

Analysis:
repetition? and give some examples {1,1} 2
range? if small, bitset is optimal if we only want to know the existence rather than indices.
hash table is a sound solution.
what about double pointer scanning?
Does sorting help?
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

	//Solution : hash tables: cost some memory, time O(n), bitset is a cheap version of hash table.
    vector<int> twoSum(vector<int> &numbers, int target) {
			unordered_map<int, int> records;
			//pre-process the input
			for(int i = 0; i < numbers.size(); i++){
				records[numbers[i]] = i; // <value, index>
			}
			vector<int> result;
			//search 
			for(int i = 0; i < numbers.size(); i++){
				int complement = target - numbers[i];
				unordered_map<int, int>::const_iterator itr = records.find(complement);
				if(itr != records.end() && itr->second != i){//exclude itself
					int j = itr->second;
					int lesser_idx = (i < j)? i : j;
					int larger_idx = (i > j)? i : j;
					result.push_back(lesser_idx + 1);//1-based index
					result.push_back(larger_idx + 1);
					return result;
				}
			}
			return result; //empty if no pairs is found.
    }
	
	//two pointer scan O(nlogn)
	vector<int> twoSum(vector<int> &numbers, int target) {
			sort(number.begin(););
			vector<int> result;
		
			return result; //empty if no pairs is found.
    }
};

int main()
{
	int array [] = {3, 2, 4};//pitfall case {3,2,4} 6
	vector<int> numbers(array,  array + sizeof(array) / sizeof(int));
	
	Solution sol;
	vector<int> result = sol.twoSum(numbers, 6);
	if(!result.empty()){
		cout << result[0] << " and " << result[1] << endl;
	}else {
		cout << "can not find pairs." << endl;
	}
	return 0;
}