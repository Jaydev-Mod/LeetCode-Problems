class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() < 2) {
            return 0; 
        }
        int maxDiff = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int nextIndex = (i + 1) % n;
            int diff = abs(nums[nextIndex] - nums[i]);
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};