/* Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 

area = f(l,r) = min(a[l], a[r]) *(r - l), and l from 0 to n-1, r from n-1 to 0
f(0, n-1) is in the interior of min f and max f.

Time complexity O(n)
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
		if(!height.size()){
			return 0;
		}
		int max_area = 0, temp = 0;
		int left = 0, right = height.size() - 1;
		while(left < right){
			int area = std::min(height[left], height[right]) * (right - left);
			if(height[left] < height[right]){
				left++;
			}else{
				right--;
			}
			max_area = std::max(max_area, area);
		}
		return max_area;
	}
};