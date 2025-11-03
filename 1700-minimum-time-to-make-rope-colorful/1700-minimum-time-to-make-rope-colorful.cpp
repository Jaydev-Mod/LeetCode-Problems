class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        if (n <= 1) {
            return 0;
        }

        int totalTime = 0;
        int maxTimeInGroup = neededTime[0];

        for (int i = 1; i < n; ++i) {
            
            if (colors[i] == colors[i - 1]) {
                totalTime += min(maxTimeInGroup, neededTime[i]);
                maxTimeInGroup = max(maxTimeInGroup, neededTime[i]);
            } 
            else {
                maxTimeInGroup = neededTime[i];
            }
        }

        return totalTime;
    }
};