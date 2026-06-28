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
    vector<int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        if(!root)
            return {};
        q.emplace(root,0);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [node,hd]=q.front();
                if(node->left)
                    q.emplace(node->left,hd-1);
                if(node->right)
                    q.emplace(node->right,hd+1);
                mp[hd]=node->data;
                q.pop();
            }
        }
        vector<int>ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};