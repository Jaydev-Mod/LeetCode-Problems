class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0; 
        int right = numbers.size()-1;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[left]+numbers[right]==target){
                return{left+1, right+1};
            }
            else if(numbers[left]+numbers[right] > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};