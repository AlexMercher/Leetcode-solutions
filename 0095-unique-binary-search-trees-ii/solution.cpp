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
    vector<TreeNode*> generate(int lo,int hi){
        if(lo>hi) return {nullptr};
        vector<TreeNode*> ans;

        for(int root=lo;root<=hi;root++){

            vector<TreeNode*> leftTree=generate(lo,root-1);
            vector<TreeNode*> rightTree=generate(root+1,hi);

            for(TreeNode* left:leftTree){
                for(TreeNode* right:rightTree){
                    TreeNode* node=new TreeNode(root);
                    node->left=left;
                    node->right=right;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};