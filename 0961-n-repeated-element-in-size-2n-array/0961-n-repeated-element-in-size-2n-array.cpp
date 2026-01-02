class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto num : mpp){
            if(num.second == n){
                return num.first;
            }
        }

        return -1;
    }
};