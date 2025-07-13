class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        int m = players.size();
        int n = trainers.size();
        while(i < m && j < n){
            if(players[i]>trainers[j]){
                j++;
            }
            else{
                i++;
                j++;
                ans++;
            }
        }
        return ans;
    }
};