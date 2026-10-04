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
    int best=INT_MIN;
    int Pathssum(TreeNode* root){
        
        if(root==nullptr) return 0;
        int left=max(0,Pathssum(root->left));
        int right=max(0,Pathssum(root->right));

        best=max(best,(root->val+left+right));
        return root->val+(max(left,right));//Very Important for choosing only 1 of the paths we cannot choose both.
    }
    int maxPathSum(TreeNode* root) {
        int n=Pathssum(root);
        return best;
    }
};