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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr) return false;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({nullptr,root});
        while(!q.empty()){
            int n=q.size();
            TreeNode* parentX=nullptr;
            TreeNode* parentY=nullptr;
            bool isx=false;
            bool isy=false;
            for(int i=0;i<n;i++){
                auto [parent,node]=q.front();
                q.pop();
                if(node->val==x){
                    isx=true;
                    parentX=parent;
                }
                if(node->val==y){
                    isy=true;
                    parentY=parent;
                }
                if(node->left) q.push({node,node->left});
                if(node->right) q.push({node,node->right});
            }
            if(isx && isy) return parentX!=parentY;
            if(isx || isy) return false;
        }
        return false;
    }
};