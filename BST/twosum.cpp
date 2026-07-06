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
    vector<int>trav;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l=0;   
        int h= trav.size()-1;
        while(h>l){
            if(trav[l]+trav[h]==k)
                return true;
            else if(trav[l]+trav[h]>k)
                h--;
            else 
                l++;
        }   
        return false;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        trav.push_back(root->val);
        inorder(root->right);
        return ;
    }
};