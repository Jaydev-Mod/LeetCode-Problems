class Solution {
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freqPairs;
        vector<int> res;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        for (auto it : mp) {
            freqPairs.push_back({it.first, it.second});
        }
        sort(freqPairs.begin(), freqPairs.end(), compare);
        for (int i = 0; i < k; i++) {
            res.push_back(freqPairs[i].first);
        }
        return res;
    }
};