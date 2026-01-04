class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currSum = 0;
            int count = 0;
            for (int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    int other = nums[i] / j;
                    if (j == other) {
                        count += 1;
                        currSum += j;
                    } else {
                        count += 2;
                        currSum += (j + other);
                    }
                }
                if (count > 4)
                    break;
            }
            if (count == 4) {
                res += currSum;
            }
        }
        return res;
    }
};