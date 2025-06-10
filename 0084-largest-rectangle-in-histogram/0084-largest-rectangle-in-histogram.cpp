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
    int largestRectangleArea(vector<int> & heights) {
        int n = heights.size();
        int res = 0;
        vector<int> ans(n);
        vector<int> nse = getNSE(heights, n);
        vector<int> pse = getPSE(heights, n);
        for(int i = 0; i < heights.size(); i++){
            ans[i] = heights[i] * (nse[i]-pse[i]-1);
        }
        for(int i = 0; i < ans.size(); i++){
            res = max(res, ans[i]);
        }
        return res;
    }
};