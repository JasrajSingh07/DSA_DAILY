/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        vector<string>str;
        while(ss>>word)
            str.push_back(word);
        int i=0;
        return build(str,i);
    }
    TreeNode* build(const vector<string>&str,int& i){
        if(str[i]=="null"){
            i++;
            return nullptr;
        }
        int value=stoi(str[i]);
        TreeNode *temp= new TreeNode(value);
        i++;
        temp->left=build(str,i);
        temp->right=build(str,i);
        return temp;
    }


    void preorder(TreeNode* root,string &ans){
        if(!root){
            ans.append("null ");
            return;
        }
        string temp =to_string(root->val);
        ans.append(temp+" ");
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));