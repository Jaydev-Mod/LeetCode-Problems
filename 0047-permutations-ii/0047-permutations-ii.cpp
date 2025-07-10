class Solution {
public:
    void getPerm(vector<int>& nums, int ind, set<vector<int>>& temp) {
        if (ind == nums.size()) {
            temp.insert(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            getPerm(nums, ind + 1, temp);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> temp;
        getPerm(nums, 0, temp);
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};