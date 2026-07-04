/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(!root)
            return -1;
        int ans=-1;
        if(root->data==x)
            return x;
        else if(root->data>x)
            ans=findCeil(root->left,x);
        else
            ans=findCeil(root->right,x);
        if(ans!=-1)
            return ans;
        if(root->data>x)
            return root->data;
        return -1;
            
    }
};
