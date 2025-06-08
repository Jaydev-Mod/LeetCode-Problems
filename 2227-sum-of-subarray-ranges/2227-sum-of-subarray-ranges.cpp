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
    vector<int> getNGE(vector<int> nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
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
    vector<int> getPGE(vector<int> nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
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

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = getNSE(nums, n);
        vector<int> pse = getPSE(nums, n);
        vector<int> nge = getNGE(nums, n);
        vector<int> pge = getPGE(nums, n);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            long long ls = i - pse[i];
            long long rs = nse[i] - i;
            long long totalWaysS = ls * rs;
            long long lg = i - pge[i];
            long long rg = nge[i] - i;
            long long totalWaysG = lg * rg;
            sum += (totalWaysG - totalWaysS) * nums[i];
        }
        return sum;
    }
};