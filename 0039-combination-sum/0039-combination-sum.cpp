class Solution {
public:
    void findCombination(int ind, int target, vector<int> candidates,
                         vector<vector<int>> &ans, vector<int> curr) {
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        if (candidates[ind] <= target) {
            curr.push_back(candidates[ind]);
            findCombination(ind, target - candidates[ind], candidates, ans,
                            curr);
            curr.pop_back();
        }
        findCombination(ind + 1, target, candidates, ans, curr);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        findCombination(0, target, candidates, ans, curr);
        return ans;
    }
};