class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        ans.push_back(curr);
        for(int i = 0; i < nums.size(); i++){
            int n = ans.size();
            for(int j = 0; j < n; j++){
                vector<int> newSubset = ans[j];
                newSubset.push_back(nums[i]);
                ans.push_back(newSubset);
            }
        }
        return ans;
    }
};