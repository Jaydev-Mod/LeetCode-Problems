class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_len = 0;
        for (auto& [num, count] : freq) {
            if (freq.find(num + 1) != freq.end()) {
                max_len = max(max_len, count + freq[num + 1]);
            }
        }
        
        return max_len;
    }
};