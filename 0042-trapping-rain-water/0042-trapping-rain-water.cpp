class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefix(n, 0);
        prefix[0] = height[0];
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }

        vector<int> suffix(n, 0);
        suffix[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }

        for(int i = 0; i < height.size(); i++){
            int leftMax = prefix[i];
            int rightMax = suffix[i];
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};