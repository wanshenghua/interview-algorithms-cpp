#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int min_dist = numeric_limits<int>::max();
		int closest_sum = -1;
		
		sort(num.begin(), num.end());
		
		int size = num.size();
		int up_bound = size - 2;
		for(int i = 0; i < up_bound; i++){
			if( num[i] == num[i - 1] && i > 0){
				continue;
			}
			int left = i + 1;
			int right = size - 1;
			while(left < right){
				if(num[left] == num[left - 1] && left > i + 1){
					++left;
					continue;
				}
				if(num[right] == num[right + 1] && right < size - 1){
					--right;
					continue;
				}
				int s = num[left] + num[right] + num[i];				
				if(s == target){
					return s;
				}else if(s < target){
					int dist = abs(s - target);
					if( dist < min_dist){
						min_dist = dist;
						closest_sum = s;
					}					
					++left;
				}else{
					int dist = abs(s - target);
					if( dist < min_dist){
						min_dist = dist;
						closest_sum = s;
					}				
					--right;
				}
			}
		}
		return closest_sum;
    }
};

int main(int argc, char **argv)
{
	Solution sol;
	//int array[] = {-1, 2, 1, -4};
	int array[] = {0,0,0};
	vector<int> num(array, array + sizeof(array) / sizeof(int) );
	cout << sol.threeSumClosest(num, 1) << endl;
	
	return 0;
}