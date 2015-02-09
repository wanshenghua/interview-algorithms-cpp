/* Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

understanding:
trade at most twice.

basic
Divide the time into 2 segments, left = [0, ..., i] and right = [i+1, ..., n-1],
then the final profit is sum of profits of left segment and right segment.
The max profit is max in final profits.

leftProfit[j] calculates profit of left segment [0, ..., j]
	leftProfit[j] = leftProfit[j-1] or prices[j] - min_so_far, whichever is larger
rightProfit[j] calculates profit of right segment [j+1, ..., n-1]
	rightProfit[j] = rightProfit[j+1] or prices[j] - max_so_far_since_end, whichever is larger

The final answer is find max of leftProfit[j]+rightProfit[j].

See. Derive an intuitive solution. Though it could be inefficient.
If you see overlap in the solutions, you can use DP.
	
Question:
explain this solution clearly.

rate: ***

Reference:
http://blog.csdn.net/fightforyourdream/article/details/14503469

Time complexity: O(n)
*/

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size() < 2){
			return 0;
		}
		//first thing after finish coding is to test edge cases: empty, single
		int n = prices.size();
		vector<int> leftProfit(n, 0), rightProfit(n, 0);
		
		//fill leftProfit[]
		int min_so_far = prices[0];
		for(int i = 1; i < n; i++){
			min_so_far = std::min(prices[i], min_so_far);
			leftProfit[i] = std::max(leftProfit[i - 1], prices[i] - min_so_far);
		}
		
		//fill rightProfit[]
		int max_so_far_since_end = prices[n - 1];
		for(int i = n - 2; i >=0; i--){
			max_so_far_since_end = std::max(prices[i], max_so_far_since_end);
			rightProfit[i] = std::max(rightProfit[i + 1], max_so_far_since_end - prices[i]);
		}
		
		int max_profit = 0;	
		for(int i = 0; i < n; i++){
			max_profit = std::max(max_profit, leftProfit[i] + rightProfit[i]);
		}
	
		return max_profit;
    }
};