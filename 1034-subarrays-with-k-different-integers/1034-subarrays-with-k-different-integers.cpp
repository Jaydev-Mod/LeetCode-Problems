class Solution {
public:
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};