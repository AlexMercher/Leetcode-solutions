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
    void inorder(TreeNode* node,vector<int>& path){
        if(node==nullptr) return;
        inorder(node->left,path);
        path.push_back(node->val);
        inorder(node->right,path);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> path;
        inorder(root,path);
        int n=path.size();
        TreeNode* dummy=new TreeNode();
        TreeNode* curr=dummy;
        for(int x:path){
            curr->right=new TreeNode(x);
            curr=curr->right;
        }
        return dummy->right;
    }
};