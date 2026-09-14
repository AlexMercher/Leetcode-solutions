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
    vector<int> value;
    void values(TreeNode* root){
        if(root==nullptr) return;
        value.push_back(root->val);
        values(root->left);
        values(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)) return;
        value.clear();
        values(root);
        int n=value.size();
        TreeNode* curr=root;
        for(int i=1;i<n;i++){
            curr->left=nullptr;
            curr->right=new TreeNode(value[i]);
            curr=curr->right;
        }
        curr->left=nullptr;
        curr->right=nullptr;
        return;
    }
};