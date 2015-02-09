/*Jump Game II 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

//Naive, time complexity O(n^2)
class Solution {
//f[i] is the minimum number of jumps to reach A[i]; f[n-1] is the answer of this problem.
public:
    int jump(int A[], int n) {
        if(n == 0 || n == 1){
            return 0;
        }
        
        vector<int> f(n, std::numeric_limits<int>::max());
        f[0] = 0;
        for(int i = 0; i < n; i++){
            int reach = i + A[i];
            for(int j = i + 1; j <= reach && j < n; j++){
                f[j] = min(f[i] + 1, f[j]);
            }
        }
        return f[n - 1];
    }
};

//Improved: 
class Solution {
//say reach is the farthest you can go by jumping once, then [0,..., reach] is covered by this, i.e. 1 jump is necessary.
//when reach can cover it, the jump is increased and we refresh the record of reach.
public:
    int jump(int A[], int n) {
        if(n == 0 || n == 1){
            return 0;
        }
        
        int min_steps = 0;
        int reach = 0; //farthest you can go at the moment
        int last_reach = 0;//last record of reach
        for(int i = 0; i < n; i++){
            if(i > last_reach){//when i passes last_reach, we can jump once, otherwise it is not necessary.
                last_reach = reach;
                ++min_steps;
            }
            reach = max(reach, i + A[i]);
        }
        return min_steps;
    }
};

//same but more intuitive
class Solution {
public:
    int jump(int A[], int n) {
        if(n == 0 || n == 1){
            return 0;
        }
        
        int min_steps = 0;
        int reach  = 0;
        int last_reach = 0;
        
        for(int i = 0; i < n; i++){
            if(i <= last_reach){
                //covered by last reach
            }else{
                last_reach = reach;
                ++min_steps;
            }
            reach = max(reach, i + A[i]);            
        }
        return min_steps;
    }
};