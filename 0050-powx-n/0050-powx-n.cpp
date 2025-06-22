class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        double half = myPow(x, n/2);
        double result = half * half;
        if(n % 2 == 1){
            result = result * x;
        }
        return result;
    }
};