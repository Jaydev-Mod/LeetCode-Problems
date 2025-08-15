class Solution {
public:
    bool isPowerOfThree(int n) {
        int num = pow(3, 19);
        return n > 0 && num%n == 0;
    }
};