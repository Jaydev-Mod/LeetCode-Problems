class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        for (int i = 0; i < haystack.size(); i++) {
            int length = 0;
            for (int j = i; j < haystack.size(); j++) {
                if (haystack[j] == needle[length]) {
                    length++;
                    if (length == needle.size()){
                        return i;
                    }
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};