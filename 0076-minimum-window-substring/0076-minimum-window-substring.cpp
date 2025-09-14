class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int have = 0, needCount = need.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            while (have == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char lChar = s[left];
                window[lChar]--;
                if (need.count(lChar) && window[lChar] < need[lChar]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};