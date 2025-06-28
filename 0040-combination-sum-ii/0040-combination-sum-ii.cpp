class Solution {
public:
    void findCombination(int ind, int target, vector<int>& candidates,
                         vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            curr.push_back(candidates[i]);
            findCombination(i+1, target-candidates[i], candidates, ans, curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); 
        findCombination(0, target, candidates, ans, curr);
        return ans;
    }
};