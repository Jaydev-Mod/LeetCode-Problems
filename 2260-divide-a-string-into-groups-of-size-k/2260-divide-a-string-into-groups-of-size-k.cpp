class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.length(); i += k) {
            string curr = "";
            for (int j = i; j < i + k; j++) {
                if (j < s.length()) {
                    curr += s[j]; 
                } else {
                    curr += fill;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};