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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode *curr=root;
        stack<TreeNode*>st;
        stack<int>rev;
        while(curr||!st.empty()){
            while(curr){
                rev.push(curr->val);
                st.push(curr);
                curr=curr->right;
            }
            curr=st.top();
            st.pop();
            curr=curr->left;
        }
        while(!rev.empty()){
            ans.push_back(rev.top());
            rev.pop();
        }
        return ans;
    }
};