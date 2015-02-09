/*Jump Game 
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

pitfall:
A[0] is your starting index
A[n-1] is your destination
*/

//greedy
class Solution {
//keep a record of how far you can go at an index
public:
    bool canJump(int A[], int n){
    	if(n == 0 || n == 1){
    		return true;
    	}
    	int reach = A[0];//farthest you can go
    	for(int i = 0; i < n - 1; i++){
    		reach = max(reach, i + A[i]);
    		if(reach == i){ //you have to stop at i, can't go further
    			return false;
    		}
    	}
    	return reach >= n - 1;
    }
};

//DP
class Solution {
//f[i] is the number of steps you can go after you have reached A[i], without even using A[i]
//f[i] = max(f[i - 1] - 1, A[i - 1] - 1), i>0
public:
    bool canJump(int A[], int n){
        if(n == 0){
            return true;
        }
        
        vector<int> f(n, 0);
        //bounary f[0] = 0;
        
        for(int i = 1; i < n; i++){
            f[i] = max(f[i - 1] - 1, A[i - 1] - 1);
            if(f[i] < 0){
                return false;
            }
        }

        return true;
    }
};

//DP compressing space complexity using rolling array
class Solution {
//f[i] is the number of steps you can go after you have reached A[i]
//f[i] = max(f[i - 1] - 1, A[i - 1] - 1), i>0
public:
    bool canJump(int A[], int n){
        if(n == 0){
            return true;
        }
        
        vector<int> f(2, 0); //space complexity  O(1)
        //bounary f[0] = 0;
        
        for(int i = 1; i < n; i++){
            f[i % 2] = max(f[(i - 1) % 2] - 1, A[i - 1] - 1);
            if(f[i % 2] < 0){
                return false;
            }
        }

        return true;
    }
};