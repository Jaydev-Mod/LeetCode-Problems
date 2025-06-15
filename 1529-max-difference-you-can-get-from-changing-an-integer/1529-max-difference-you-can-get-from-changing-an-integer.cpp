class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        unordered_set<char> unique_digits(s.begin(), s.end());
        int maxNum = num;
        int minNum = num;
        for(char d : unique_digits){
            for(char ch = '0'; ch <= '9'; ch++){
                string new_s = s;
                replace(new_s.begin(), new_s.end(), d, ch);
                int currNum = stoi(new_s);
                if(currNum > maxNum){
                    maxNum = currNum;
                }
                else if(currNum < minNum){
                    if (new_s[0] == '0'){
                        continue;
                    }
                    minNum = currNum;
                }
            }
        }
        return maxNum - minNum;
    }
};