#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		int size = num.size();
		int up_bound = size - 3;
		
		for(int i = 0; i < up_bound; i++){	
			if(num[i] == num[i - 1] && i > 0){
				continue;
			}
			for(int j = i + 1; j < size - 2; j++){
				if(num[j] == num[j - 1] && j > i + 1){
					continue;
				}
				int l = j + 1;
				int r = size - 1;
				while(l < r){
					if(num[l] == num[l - 1] && l > j + 1){
						++l;
						continue;
					}
					if(num[r] == num[r + 1] && r < size - 1){
						--r;
						continue;
					}
					int s = num[l] + num[r] + num[i] + num[j];
					if(s == target){
						vector<int> quadruplet(4);
						quadruplet[0] = num[i];
						quadruplet[1] = num[j];
						quadruplet[2] = num[l];
						quadruplet[3] = num[r];
						result.push_back(quadruplet);
						++l;
						--r;
					}else if( s < target){
						++l;
					}else{
						--r;
					}
				}
			}
		}
		return result;
    }
};

int main()
{
	Solution sol;
	int array[] = {1, 0, -1, 0, -2, 2};
	vector<int> num(array, array + sizeof(array) / sizeof(int));
	vector<vector<int> > result = sol.fourSum(num, 0);
	
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < 4; j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}