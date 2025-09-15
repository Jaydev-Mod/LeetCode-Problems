class Solution {
public:
    int dpRecurr(vector<int>& dp, int n) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = dpRecurr(dp, n - 1) + dpRecurr(dp, n - 2);
        return dp[n];
    }

    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return dpRecurr(dp, n);
    }
};