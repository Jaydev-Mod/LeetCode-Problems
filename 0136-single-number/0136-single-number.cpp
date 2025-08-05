class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto curr : mp){
            if(curr.second == 1){
                return curr.first;
            }
        }
        return -1;
    }
};