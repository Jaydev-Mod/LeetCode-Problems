class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int targetIndex = 0;
        
        // Iterate through numbers 1 to n
        for (int i = 1; i <= n; i++) {
            // Optimization: If we have built the full target, stop early
            if (targetIndex == target.size()) {
                break;
            }
            
            // We always have to push the current stream number first
            result.push_back("Push");
            
            // Check if the current stream number matches the target number
            if (target[targetIndex] == i) {
                // It's a match, keep it in stack, move to next target
                targetIndex++;
            } else {
                // It's not a match, remove it immediately
                result.push_back("Pop");
            }
        }
        
        return result;
    }
};