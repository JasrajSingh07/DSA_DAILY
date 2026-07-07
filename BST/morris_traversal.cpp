/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        Node* curr=root;
        vector<int>ans;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right&&prev->right!=curr)
                    prev=prev->right;
                if(prev->right==curr){
                    ans.push_back(curr->data);
                    prev->right=nullptr;
                    curr=curr->right;
                }
                else{
                    prev->right=curr;
                    curr=curr->left;
                }
            }
            
            
        }
        return ans;
    }
};