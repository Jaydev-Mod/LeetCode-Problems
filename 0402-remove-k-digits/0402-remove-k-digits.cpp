class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;  
        for (char c : num) {
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        while (k-- > 0) res.pop_back();
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};