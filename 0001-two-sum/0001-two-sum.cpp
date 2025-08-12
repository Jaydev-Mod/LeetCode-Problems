class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int otherNum = target - num;
            if (mpp.find(otherNum) != mpp.end()) {
                return {mpp[otherNum], i};
            }
            mpp[num] = i;
        }
        return {};
    }
};