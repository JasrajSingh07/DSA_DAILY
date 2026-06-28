class Solution {
public:
    int dia=0;
    int diameterOfBinaryTree(TreeNode* root){
        dfs(root);
        return dia;
    }
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left+right>dia)
            dia=left+right;
        return max(left,right)+1;
        
    }
};