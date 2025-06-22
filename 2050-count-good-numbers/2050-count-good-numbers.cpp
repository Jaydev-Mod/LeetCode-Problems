class Solution {
public:
    const int M = 1e9 + 7;
    int myPow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        long long half = myPow(x, n / 2);
        long long result = (half * half) % M;
        if (n % 2 == 1) {
            result = (result * x) % M;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)myPow(5, (n + 1) / 2) * myPow(4, n / 2) % M;
    }
};