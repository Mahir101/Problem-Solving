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
    bool recur(TreeNode* p, TreeNode *q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }

        if((p == nullptr && q != nullptr)  || (p != nullptr && q == nullptr)) {
            return false;
        }

        if(p->val == q->val) {
            return recur(p->left, q->left) && recur(p->right, q->right);
        } else {
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recur(p,q);
    }
};
