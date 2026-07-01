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
    bool isSymmetric(TreeNode* root) {
        if(!root->left&&!root->right)
            return true;
        return check(root->left,root->right);
        
    }
    bool check(TreeNode* l,TreeNode* r){
        if(!l&&!r)
            return true;
        if((!l&&r)||(!r&&l))
            return false;
        if(l->val!=r->val)
            return false;
        bool lcheck=check(l->left,r->right);
        bool rcheck=check(l->right,r->left);
        if(lcheck&&rcheck)
            return true;
        return false;
    }

};