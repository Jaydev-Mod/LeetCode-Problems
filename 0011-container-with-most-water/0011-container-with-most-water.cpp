class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = -1;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int currTank = (right - left) * min(height[left], height[right]);
            maxWater = max(currTank, maxWater);
            if (height[left] < height[right]) {
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};