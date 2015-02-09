/* Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

understanding:
basic:
p_0, p_1, ..., p_{n-1}

for i =0->n-1
	for j = i+1
		max (p_j - p_i)

advanced:
1. keep a record of lowest price in the past
2. keep a record of highest profit so far using 1.
*/

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		//first thing after finish coding is to test edge cases: empty, single
		if(!prices.size()){
			return 0;
		}
        int min_so_far = prices[0]; //record lowest so far
		int max_profit = 0;//use first item as baseline.
		for(int i = 1; i < prices.size(); i++){
			min_so_far = std::min(prices[i], min_so_far);
			max_profit = std::max(max_profit, prices[i] - min_so_far);
		}
		return max_profit;
    }
};