/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Analysis:
unique? no self reference twice
no indices needed? only numbers.
repetition?

Solution:
Sorted array, use two pointers to scan.
Take a look at previous item to avoid repetition.
Respect the boundary of the pointers.

complexity
O(n^2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//Solution : hash tables: cost some memory, time O(n)
    vector<vector<int> > threeSum(vector<int> &numbers) {
		sort(numbers.begin(), numbers.end());
		vector<vector<int> > result;
		int left=-1, right=-1;
		int size = numbers.size();
		int up_bound = size - 2;
		for(int i = 0; i < up_bound; i++){
			if(numbers[i] == numbers[i-1] && i > 0) { //compare to last item and respect the boundary-key
				continue;
			}
			left = i + 1;
			right = size - 1;
			while(left < right){
				if(numbers[left] == numbers[left - 1] && left > i + 1){//compare to the last item
					++left;
					continue;
				}
				if(numbers[right] == numbers[right + 1] && right < size - 1){ //compare to last item
					--right;
					continue;
				}
				int s = numbers[i] + numbers[left] + numbers[right];
				if(0 == s){
					vector<int> triplet(3);
					triplet[0] = numbers[i];
					triplet[1] = numbers[left];
					triplet[2] = numbers[right];
					result.push_back(triplet);
					++left;
					--right;
				}else if (s < 0){
					++left;
				}else{
					--right;
				}				
			}
		}
		return result;
    }
};

int main()
{
	int array [] = {-1, 0, 1, 2, -1, 4};
	vector<int> numbers(array,  array + sizeof(array) / sizeof(int));
	
	Solution sol;
	vector<vector<int> > result = sol.threeSum(numbers);
	if(!result.empty()){
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < 3; j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}else {
		cout << "can not find pairs." << endl;
	}
	return 0;
}