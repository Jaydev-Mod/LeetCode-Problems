class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; 
        for (int i = 0; i < numRows; i++) {
            long long ans = 1; 
            vector<int> ansRow;
            ansRow.push_back(1); 
            for (int col = 1; col <= i; col++) {
                ans = ans * (i - col + 1);
                ans = ans / col;
                ansRow.push_back(ans);
            }
            result.push_back(ansRow);
        }
        return result;
    }
};
