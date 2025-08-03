class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend > 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        long ans = 0;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        while(n >= d){
            int count  = 0;
            while(n >= (d << (count+1))){
                count++;
            }
            ans += (1L << count);
            n -= (d<<count);
        }
        if (ans > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
        return sign ? ans : (-1 * ans);
    }
};