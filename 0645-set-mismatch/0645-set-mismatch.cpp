class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int duplicate;
        
        for(int val : nums){
            if(st.count(val)){
                duplicate = val;
            }
            st.insert(val);
        }

        int sum = 0;
        for(int it : st){
            sum += it;
        }

        vector<int> ans;
        int requiredSum = (n*(n+1))/2;
        int required = requiredSum - sum;
        ans.push_back(duplicate);
        ans.push_back(required);
        return ans;
    }
};