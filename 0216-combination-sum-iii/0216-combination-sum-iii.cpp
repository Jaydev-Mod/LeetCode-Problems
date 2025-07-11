class Solution {
public:
    void combinations(int k, int n, int ind, int sum, vector<int>& arr,
                      vector<vector<int>>& ans) {
        if (k == 0) {
            if (sum == n) {
                ans.push_back(arr);
            }
            return;
        }
        if (k == 0 || n <= 0 || ind > 9) return;

        arr.push_back(ind);
        combinations(k-1, n, ind+1, sum+ind, arr, ans);
        arr.pop_back();
        combinations(k, n, ind+1, sum, arr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        combinations(k, n, 1, 0, arr, ans);
        return ans;
    }
};