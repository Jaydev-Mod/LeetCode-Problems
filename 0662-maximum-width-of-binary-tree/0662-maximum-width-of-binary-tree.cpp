class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            ans = max(ans, (int)(last - first + 1));
            for(int i = 0; i < len; i++){
                auto que = q.front();
                TreeNode * temp = que.first;
                long long ind = que.second;
                q.pop();
                ind -= first;
                if(temp->left){
                    q.push({temp->left, 2 * ind + 1});
                }
                if(temp->right){
                    q.push({temp->right, 2 * ind + 2});
                }
            }
        }
        return ans;
    }
};
