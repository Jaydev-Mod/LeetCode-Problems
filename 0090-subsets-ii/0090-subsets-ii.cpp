class Solution {
public:
    void getAllSubSet(vector<int>& nums, int i, vector<vector<int>>& ans,
                      vector<int>& curr) {
        if (i == nums.size()){
            ans.push_back({curr});
            return;
        }
        curr.push_back(nums[i]);
        getAllSubSet(nums, i+1, ans, curr);
        curr.pop_back();
        int index = i+1;
        while(index < nums.size() && nums[index]==nums[index-1]){
            index++;
        }
        getAllSubSet(nums, index, ans, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        getAllSubSet(nums, 0, ans, curr);
        return ans;
    }
};