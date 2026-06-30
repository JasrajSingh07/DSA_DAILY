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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        path(root);
        return ans;
    }
    int path(TreeNode* root){
        if(!root)
            return 0;
        int left=path(root->left);
        int right=path(root->right);
        ans=max(ans,(left<0?0:left)+root->val+(right<=0?0:right));
        return root->val+max(0,max(left,right));
    }
};