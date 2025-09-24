class Solution {
public:
    int solve(vector<vector<int>>& dp, int start, int start2, int m, int n) {
        if (start == m - 1 && start2 == n - 1) {
            return 1;
        }

        if (start >= m || start2 >= n) {
            return 0;
        }

        if(dp[start][start2] != -1) return dp[start][start2];

        int right = solve(dp, start, start2+1, m, n);
        int down = solve(dp, start+1, start2, m, n);

        return dp[start][start2] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, 0, 0, m, n);
    }
};