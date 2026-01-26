class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int lowest = INT_MAX;

        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i+1] - arr[i] < lowest){
                lowest = arr[i+1] - arr[i];
            }
        }

        for(int i = 0; i < arr.size()-1; i++){
            vector<int> curr;
            if(arr[i+1]-arr[i] == lowest){
                curr.push_back(arr[i]);
                curr.push_back(arr[i+1]);
                result.push_back(curr);
            }
        }

        return result;
    }
};