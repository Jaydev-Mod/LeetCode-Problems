class Solution {
public:

    vector<int> getNSE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getPSE(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top(); 
            }
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = getNSE(arr, n);
        vector<int> pse = getPSE(arr, n);
        long long sum = 0;
        int M = 1e9+7;
        
        for(int i = 0; i < arr.size(); i++){
            long long ls = i - pse[i];
            long long rs = nse[i] - i;
            long long totalWays = ls * rs;
            sum = (sum + (arr[i]*totalWays)%M)%M;
        }
        return sum;
    }
};