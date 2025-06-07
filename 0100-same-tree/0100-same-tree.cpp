/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return {-2};
        }
        ans.push_back(root->val);
        
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans1 = preorderTraversal(p);
        vector<int> ans2 = preorderTraversal(q);

        for(int i = 0; i < ans1.size(); i++){
            if(ans1[i]!=ans2[i]){
                return false;
                break;
            }
        }
        return true;
    }
};