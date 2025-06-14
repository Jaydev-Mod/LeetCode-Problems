class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        unordered_set<char> unique_digits(s.begin(), s.end());
        int maxnum = num;
        int minnum = num;
        for (char d : unique_digits) {
            for (char new_d = '0'; new_d <= '9'; new_d++){
                string new_s = s;
                replace(new_s.begin(), new_s.end(), d, new_d);
                int current_num = stoi(new_s);
                if(current_num > maxnum){
                    maxnum = current_num;
                }
                if (current_num < minnum) {
                    minnum = current_num;
                }
            }
        }
        return maxnum - minnum;
    }
};