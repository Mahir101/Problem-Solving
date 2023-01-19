/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNodet; *lef
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> output;
    void recur(TreeNode* root) {
        if(root==nullptr) {
            return;
        }
        output.push_back(root->val);
        recur(root->left);
        recur(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        recur(root);
        return output;
    }
};
