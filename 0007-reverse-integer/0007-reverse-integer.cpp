class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x != 0){
            int num = x % 10;
            x /= 10;
            ans = ans * 10 + num;
            
            if(ans > INT_MAX || ans < INT_MIN){
                return 0;
            }
        }
        return (int)ans;
    }
};