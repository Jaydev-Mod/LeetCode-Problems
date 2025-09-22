class Solution {
public:
    int solve(int ind, vector<int>& dp, vector<int>& nums){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick = nums[ind] + solve(ind-2, dp, nums);
        int notPick = 0 + solve(ind-1, dp, nums);

        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != nums.size()-1) temp1.push_back(nums[i]);
            if(i != 0) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        int ans1 = solve(temp1.size()-1, dp1, temp1);
        int ans2 = solve(temp2.size()-1, dp2, temp2);

        return max(ans1, ans2);
    }
};