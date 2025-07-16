class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evencount = 0;
        int oddcount = 0;

        for(int &num : nums){
            if(num%2==0){
                evencount++;
            }else{
                oddcount++;
            }
        }

        int alternatecount = 1;
        int parity = nums[0]%2;
        for (int i = 1; i < n; i++) {
            int currparity = nums[i]%2;
            if(currparity != parity){
                alternatecount++;
                parity = currparity;
            }
        }
        return max({evencount, oddcount, alternatecount});
    }
};