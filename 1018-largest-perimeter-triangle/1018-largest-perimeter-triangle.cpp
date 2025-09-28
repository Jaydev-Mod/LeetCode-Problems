class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int area = 0;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = j+1;
            if(j < nums.size() && k < nums.size()){
                if((nums[i]+nums[j] > nums[k]) && (nums[j]+nums[k] > nums[i]) && (nums[i] + nums[k] > nums[j])){
                    area = max(area, (nums[i]+nums[j]+nums[k]));
                }
            }
        }
        return area;
    }
};