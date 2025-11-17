class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int position = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1 && position == INT_MIN){
                position = i;
                continue;
            }
            if(nums[i] == 1){
                if(i - position <= k){
                    return false;
                }
                position = i;
            }
        }
        return true;
    }
};