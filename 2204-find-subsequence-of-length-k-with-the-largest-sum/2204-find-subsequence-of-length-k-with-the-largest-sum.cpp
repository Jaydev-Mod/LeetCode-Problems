class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int, int>> indexedNum;

        for (int i = 0; i < nums.size(); i++) {
            indexedNum.emplace_back(nums[i], i);
        }

        sort(indexedNum.begin(), indexedNum.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        sort(indexedNum.begin(), indexedNum.begin() + k,
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        for (int i = 0; i < k; i++) {
            ans.push_back(indexedNum[i].first);
        }
        return ans;
    }
};