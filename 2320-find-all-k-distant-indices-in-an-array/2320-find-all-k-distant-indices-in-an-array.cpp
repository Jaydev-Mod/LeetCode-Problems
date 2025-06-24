class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> position;
        unordered_set<int> ansSet;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==key){
                position.push_back(i);
            }
        }
        if(position.size()==0){
            return {};
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < position.size(); j++){
                if(abs(i-position[j])<=k){
                    ansSet.insert(i);
                }
            }
        }
        vector<int> ans(ansSet.begin(), ansSet.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};