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
    void encode(TreeNode* root,string& s){
        if(root==nullptr){
            s+="#,";
            return;
        }
        s+=to_string(root->val)+",";
        encode(root->left,s);
        encode(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        encode(root,s);
        return s;
    }
    TreeNode* decode(stringstream& data){
        string val;
        getline(data,val,',');
        if(val=="#") return nullptr;

        TreeNode* root=new TreeNode(stoi(val));
        root->left=decode(data);
        root->right=decode(data);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));