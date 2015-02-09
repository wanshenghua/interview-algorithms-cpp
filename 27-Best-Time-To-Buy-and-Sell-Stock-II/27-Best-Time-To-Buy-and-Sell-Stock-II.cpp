/* Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

understanding:
Original version: trade one time, buy before sell.
This version: trade multiple times, buy before sell.

key: when the price is raise, max profit can be obtained through
any of the method:
1. buy at min and sell at max
2. buy and sell at the next day
So, max profit = max_profit of each trading in 2 consecutive days.
*/

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		//first thing after finish coding is to test edge cases: empty, single
		int max_profit = 0;
		for(int i = 1; i < prices.size(); i++){
			if(prices[i] > prices[i - 1]){
				max_profit += (prices[i] - prices[i - 1]);
			}
		}
		return max_profit;
    }
};