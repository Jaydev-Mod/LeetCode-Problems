class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long powerValue = 1;
        for (int i = s.length()-1; i >= 0; i--) {
            if(s[i]=='0'){
                count++;
            }else if(powerValue <= k){
                k -= powerValue;
                count++;
            }
            
            if(powerValue <= k){
                powerValue <<= 1;
            }
        }
        return count;
    }
};