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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(0,1001,preorder);
    }

    TreeNode* build(int l,int h,vector<int>&pre){
        if(i>=pre.size())
            return nullptr;
        if(pre[i]>=h||pre[i]<=l)
            return nullptr;

        TreeNode *temp =new TreeNode(pre[i]);
        i++;
        temp->left=build(l,pre[i-1],pre);
        temp->right=build(pre[i-1],h,pre);
        return temp;
    }
};