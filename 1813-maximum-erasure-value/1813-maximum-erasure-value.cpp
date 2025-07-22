class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool seen[10001] = {false};
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen[nums[right]]) {
                currentSum -= nums[left];
                seen[nums[left]] = false;
                ++left;
            }
            currentSum += nums[right];
            seen[nums[right]] = true;
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return maxSum;
    }
};