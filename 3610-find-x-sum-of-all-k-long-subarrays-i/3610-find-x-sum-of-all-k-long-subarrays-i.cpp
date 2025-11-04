class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans; 
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            unordered_map<int, int> freq;
             for (int j = i; j < i + k; j++){
                freq[nums[j]]++;
             }
        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first > b.first;
        });
        int sum = 0, cnt = 0;
        for (auto& p : vec) {
            int take = min(p.second, k);
            sum += p.first * take;
            cnt++;
            if (cnt == x)
                break;
        }
        ans.push_back(sum);
    }
    return ans;
}
}
;