/*Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        std::unordered_map<int, bool> used;
        //mark existence using hashtable
        for(auto val: num){
            used[val] = false;//key: false indicates existence in hashtable
        }
        int max_len = 0;
        for(auto val: num){
           if(used[val]){
               continue;//key: ignore examined values -> this makes O(n)
           }
           used[val] = true;//examine this value's neighborhood, and mark the neighborhood-> this makes O(n)
           int len = 1;
           for(int i = val + 1; used.find(i) != used.end(); i++){
               used[i] = true;//key: mark used values -> this makes O(n)
               ++len;
           }
           for(int i = val - 1; used.find(i) != used.end(); i--){
               used[i] = true;
               ++len;
           }
           max_len = max(len, max_len);
        }
        return max_len;
    }
};