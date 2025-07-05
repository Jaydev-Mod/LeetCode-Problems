class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        if (arr.empty()) return -1;
        
        int maxElement = *max_element(arr.begin(), arr.end());
        vector<int> hash(maxElement + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i]]++;
        }
        for (int i = hash.size() - 1; i > 0; i--) {
            if (hash[i] == i) {
                return i;
            }
        }
        return ans;
    }
};