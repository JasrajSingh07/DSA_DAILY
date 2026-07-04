/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        if(!root)
            return -1;
        int ans=-1;
        if(root->data==k)
            return k;
        else if(root->data>k)
            ans=findMaxFork(root->left,k);       
        else
            ans=findMaxFork(root->right,k);
        if(ans!=-1)
            return ans;
        else if(root->data<k)
            return root->data;
        return -1;
    }
};