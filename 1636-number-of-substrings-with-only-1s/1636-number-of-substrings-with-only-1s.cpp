class Solution {
public:
    int numSub(string s) {
        int count = 0;
        int result = 0;
        int modulo = 1e9+7;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                count++;
                result = (result + count) % modulo;
            }else{
                count = 0;
            }
        }
        return result;
    }
};