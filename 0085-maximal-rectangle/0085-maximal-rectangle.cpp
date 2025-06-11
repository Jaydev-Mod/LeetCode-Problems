class Solution {
public:
    vector<int> getNSE(vector<int> nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getPSE(vector<int> nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> ans(n);
        vector<int> nse = getNSE(heights, n);
        vector<int> pse = getPSE(heights, n);
        for (int i = 0; i < heights.size(); i++) {
            ans[i] = heights[i] * (nse[i] - pse[i] - 1);
        }
        for (int i = 0; i < ans.size(); i++) {
            res = max(res, ans[i]);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }
                prefix[i][j] = sum;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            maxi = max(maxi, largestRectangleArea(prefix[i]));
        }
        return maxi;
    }
};