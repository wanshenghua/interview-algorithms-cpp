/* Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

n = 1 + n - 1 or 2 + n - 2
therefore
a[n] is the number of ways to arrive at n.
a[n] = a[n-1] + a[n-2]
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways_to_arrive(n + 1, 0);
		ways_to_arrive[0] = 1;
		ways_to_arrive[1] = 1;
		
		for(int i = 2; i <= n; i++){
			ways_to_arrive[i] = ways_to_arrive[i - 1] + ways_to_arrive[i - 2];
		}
		
		return ways_to_arrive[n];
    }
};