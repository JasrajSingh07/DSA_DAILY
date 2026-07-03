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
    int left;
    int kthSmallest(TreeNode* root, int k) {
        left=k;
        return helper(root);

    }
    int helper(TreeNode* root) {
        if(!root)
            return -1;
        int l=helper(root->left);
        if(l!=-1)
            return l;
        left--;
        if(left==0)
            return root->val;
        int r=helper(root->right);
        if(r!=-1)
            return (r);
        else return -1;

    }
};