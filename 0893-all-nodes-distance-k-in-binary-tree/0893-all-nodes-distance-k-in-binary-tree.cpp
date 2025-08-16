/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentNodes;

    void parentNode(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left) {
            parentNodes[root->left] = root;
            parentNode(root->left);
        }
        if (root->right) {
            parentNodes[root->right] = root;
            parentNode(root->right);
        }
    }

    void bfs(TreeNode* target, int k, vector<int>& ans) {
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while (!q.empty()) {
            int len = q.size();
            if (k == 0)
                break;
            while (len--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left &&
                    visited.find(temp->left->val) == visited.end()) {
                    q.push(temp->left);
                    visited.insert(temp->left->val);
                }
                if (temp->right &&
                    visited.find(temp->right->val) == visited.end()) {
                    q.push(temp->right);
                    visited.insert(temp->right->val);
                }
                if (parentNodes.find(temp) != parentNodes.end() &&
                    visited.find(parentNodes[temp]->val) == visited.end()) {
                    q.push(parentNodes[temp]);
                    visited.insert(parentNodes[temp]->val);
                }
            }
            k--;
        }
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        parentNode(root);
        bfs(target, k, ans);
        return ans;
    }
};