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
    bool isvalid=true;
    void is(TreeNode* root,int val){
        if(root==nullptr) return;
        is(root->left,val);
        if(root->val!=val){
            isvalid=false;
            return;
        }
        is(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        is(root,root->val);
        return isvalid;
    }
};