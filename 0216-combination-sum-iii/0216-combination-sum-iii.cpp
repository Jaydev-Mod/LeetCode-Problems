class Solution {
public:
    void combinations(int k, int n, int ind, int sum, vector<int>& arr,
                      set<vector<int>>& curr) {
        if (k == 0) {
            if (sum == n) {
                curr.insert(arr);
            }
            return;
        }
        if (ind == 10) return;

        arr.push_back(ind);
        combinations(k-1, n, ind+1, sum+ind, arr, curr);
        arr.pop_back();
        combinations(k, n, ind+1, sum, arr, curr);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> curr;
        vector<int> arr;
        combinations(k, n, 1, 0, arr, curr);
        vector<vector<int>> ans(curr.begin(), curr.end());
        return ans;
    }
};