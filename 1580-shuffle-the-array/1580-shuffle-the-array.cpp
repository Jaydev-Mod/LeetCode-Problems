class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2*n);
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int y = nums[i+n];
            result[2*i] = x;
            result[2*i + 1] = y;
        }
        return result;
    }
};