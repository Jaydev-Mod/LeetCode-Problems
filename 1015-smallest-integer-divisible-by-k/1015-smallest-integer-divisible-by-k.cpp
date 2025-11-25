class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0, length = 0;
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        while(++length){
            remainder = (remainder * 10 + 1) % k;
            if(remainder == 0) return length;
        }
        return -1;
    }
};