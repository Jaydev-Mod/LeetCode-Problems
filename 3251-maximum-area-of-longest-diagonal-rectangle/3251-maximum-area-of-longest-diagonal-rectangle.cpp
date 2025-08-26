class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int maxi = 0;
        int maxiDia = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            int j = 0;
            int diagonal = dimensions[i][j] * dimensions[i][j] +
                                dimensions[i][j + 1] * dimensions[i][j + 1];
            if (diagonal > maxiDia) {
                maxiDia = diagonal;
                maxi = i;
                ans = dimensions[i][0] * dimensions[i][1];
            }
            else if(diagonal == maxiDia){
                int currentArea = dimensions[i][0] * dimensions[i][1];
                if (currentArea > ans) {
                    ans = currentArea;
                    maxi = i; 
                }
            }
        }
        return ans;
    }
};