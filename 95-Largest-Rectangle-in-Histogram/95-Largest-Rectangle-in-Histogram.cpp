#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int size = height.size();
        int maxArea = 0;
        int i = 0;
        int tp = 0;
        height.push_back(0);
        stack<int> s;
        while(i < height.size()){
            if(s.empty() || height[s.top()] <= height[i]){
                s.push(i++);
            }else{
                tp = s.top();
                s.pop();
                int width = (s.empty()) ? i : (i - s.top() - 1);
                int maxAreaContainsThisBarAsLowest = height[tp] * width;
                maxArea = max(maxArea, maxAreaContainsThisBarAsLowest);
            }
        }
        return maxArea;
    }
};