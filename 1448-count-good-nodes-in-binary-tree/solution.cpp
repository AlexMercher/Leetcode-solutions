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
    int dfs(TreeNode* root,int maxNow){
        if(!root) return 0;
        int good=0;
        if(root->val>=maxNow) good=1;
        int newmax=max(maxNow,root->val);
        good+=dfs(root->left,newmax);
        good+=dfs(root->right,newmax);

        return good;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};