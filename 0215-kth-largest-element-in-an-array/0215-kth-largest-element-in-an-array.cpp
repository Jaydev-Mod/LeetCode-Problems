class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = -1;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < k ; i++){
            if(i == k-1){
                ans = nums[i];
            }
        }
        return ans;
    }
};