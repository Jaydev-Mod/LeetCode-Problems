class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x2 >= x1 && y2 <= y1) {

                    bool check = true;
                    for (int k = 0; k < n; k++) {
                        if (j == k || i == k)
                            continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x3>=x1 && x3<=x2 && y3 <= y1 && y3 >= y2){
                            check = false;
                            break;
                        }
                    }
                    if (check) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};