class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                ans.push_back(asteroid);
            } else {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroid)) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() == abs(asteroid)) {
                    ans.pop_back();
                } else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroid);
                }
            }
        }
        return ans;
    }
};