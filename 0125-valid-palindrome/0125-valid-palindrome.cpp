class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for(int i = 0; i < s.length(); i++){
            if(isalnum(s[i])){
                filtered += tolower(s[i]);
            }
        }
        int left = 0;
        int right = filtered.length() - 1;
        while(left <= right){
            if(filtered[left] != filtered[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};