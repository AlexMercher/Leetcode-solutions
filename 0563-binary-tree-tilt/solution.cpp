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
    int ans;
    int solve(TreeNode* node){
        if(node==nullptr) return 0;
        int leftsum=solve(node->left);
        int rightsum=solve(node->right);
        ans+=abs(leftsum-rightsum);
        return node->val+leftsum+rightsum;
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return ans;
    }
};