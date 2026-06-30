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
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        paths(root,targetSum,path);
        return ans;
    }
    void paths(TreeNode* root,int left,vector<int>&path){
        if(!root)
            return ;
        int rem=left-root->val;
        path.push_back(root->val);
        if(!root->left&&!root->right&&rem==0)
            ans.push_back(path);
        paths(root->left,rem,path);
        paths(root->right,rem,path);
        path.pop_back();
    }

};