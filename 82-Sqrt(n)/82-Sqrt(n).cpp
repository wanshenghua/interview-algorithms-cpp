/* Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x.

key: newton's method or binary search since sqrt(n) <= 1/2*n + 1
*/


class Solution {
public:
    int sqrt(int n) {
        if(n == 0){
            return 0;
        }
        
        double res = 1.0;
        double prev_res = 2.0;
        while(fabs(res - prev_res) > 1e-5){
            prev_res = res;
            res = 0.5 * res + n / 2.0 / res;
        }
        return (int)res;
    }
};

class Solution {
public:
    int sqrt(int n) {
        if(n == 0 || n == 1){ //avoid boundary cases
            return n;
        }
        
        double lb = 0;
        double ub  = n / 2.0 + 1;
		return (int)find_sqrt(lb, ub, n);
    }
	long long find_sqrt(long long lb, long long ub, long long n){
		if(lb + 1 == ub){ //if in [lb, lb+1], return lb.
			return lb; //cutoff rounding to lb.
		}
		long long mid = (lb +  ub) / 2;
		long long sq = mid * mid;
		if(sq == n){
			return mid;
		}else if(sq < n){
			return find_sqrt(mid, ub, n);
		}else{
			return find_sqrt(lb, mid, n);
		}
	}
};
