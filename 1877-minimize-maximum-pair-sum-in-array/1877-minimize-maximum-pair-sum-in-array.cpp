class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = nums.size()-1;
        int ans = INT_MIN;
        for(int left = 0; left < nums.size()/2; left++){
            if(nums[left]+nums[right] > ans){
                ans = nums[left]+nums[right];
            }
            right--;
        }
        return ans;
    }
};