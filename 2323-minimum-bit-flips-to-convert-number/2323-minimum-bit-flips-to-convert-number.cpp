class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal)return 0;
        int count;
        int ans = start ^ goal;
        while(ans > 0){
            ans = ans & (ans - 1);
            count++;
        }
        return count;
    }
};