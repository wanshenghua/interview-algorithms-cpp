/*Pow(x, n)
Implement pow(x, n). 

idea: binary search
pitfalls: n can be negative
*/

class Solution {
public:
    double pow(double x, int n) {
        if(n >= 0){
            return power(x, n);
        }else{
            return 1.0 / power(x, -n);
        }
    }
    
    double power(double x, int n){
        if(n == 0){
            return 1.0;
        }
        
        double val = power(x, n / 2);
        if(n % 2 == 0){
            return val * val;
        }else{
            return val * val * x;
        }
    }
};