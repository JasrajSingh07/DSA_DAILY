/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int left;
    int kthLargest(Node *root, int k) {
        left=k;
        return kth(root);
        // Your code here
        
    }
    int kth(Node *root){
        if(!root)
            return -1;
        int r=kth(root->right);
        if(r!=-1)
            return r;
        left--;
        if(left==0)
            return root->data;
        int l=kth(root->left);
        if(l!=-1)
            return l;
        return -1;
    }
    
};