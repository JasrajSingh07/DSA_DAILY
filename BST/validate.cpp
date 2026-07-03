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
    bool isValidBST(TreeNode* root) {
        return valid(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }
    bool valid(TreeNode* root,long long low,long long high){
        if(!root)
            return true;
        if(!(root->val>low)||!(root->val<high))
            return false;
        bool l=valid(root->left,low,root->val);
        bool r=valid(root->right,root->val,high);
        return (r&&l);

    }
};