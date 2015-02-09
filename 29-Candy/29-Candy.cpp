/* Candy

 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
 
			candy[i - 1] + 1, if ratings[i] > ratings[i-1]
candy[i] =  1, if ratings[i] = ratings[i-1]

understanding:
   Children with a higher rating get more candies than their neighbors.
  increasing with the ratings, however same rating is not higher.
*/
#include <algorithm>
#include <vector>
class Solution {
public:
    int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> left(n, 1), right(n, 1);
		
		for(int i = 1; i < n; i++){
			if(ratings[i] > ratings[i - 1]){
				left[i] = left[i - 1] + 1;
			}
		}
		
		for(int i = n - 2; i >= 0; i--){
			if(ratings[i] > ratings[i + 1]){
				right[i] = right[i+1] + 1;
			}
		}
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += max(left[i], right[i]);
		}
		return sum;
    }
};