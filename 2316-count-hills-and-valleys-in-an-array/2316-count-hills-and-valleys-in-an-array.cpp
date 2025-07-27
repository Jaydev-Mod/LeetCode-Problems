class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 1;
        while (j + 1 < nums.size()) {
            if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||
                (nums[i] > nums[j] && nums[j] < nums[j + 1])) {
                ans++;
                i = j;
            }
            j++;
        }
        return ans;
    }
};