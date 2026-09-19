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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        root->val=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int levelsum=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                if(node->left) levelsum+=node->left->val;
                if(node->right) levelsum+=node->right->val;
                q.push(node); // Reconstructing the same queue;
            }

            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                int siblingsum=0;
                if(node->left) siblingsum+=node->left->val;
                if(node->right) siblingsum+=node->right->val;
                if(node->left){
                    node->left->val=levelsum-siblingsum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=levelsum-siblingsum;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};