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
    pair<int,int> solve(TreeNode* node){
        if(node==nullptr) return {0,0};
        auto left=solve(node->left);
        auto right=solve(node->right);
        int rob=node->val+left.second+right.second;
        int skip=max(left.first,left.second)+max(right.first,right.second);
        return {rob,skip};
    }
    int rob(TreeNode* root) {
        auto ans=solve(root);
        return max(ans.first,ans.second);
    }
};