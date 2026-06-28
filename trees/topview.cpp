/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        if(!root)
            return {};
        q.emplace(root,0);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node=q.front().first;
                if(node->left)
                    q.emplace(node->left,q.front().second-1);
                if(node->right)
                    q.emplace(node->right,q.front().second+1);
                if(!mp.count(q.front().second))
                    mp.insert({q.front().second,node->data});
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