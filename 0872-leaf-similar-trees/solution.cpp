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
    void inorder(TreeNode* root,vector<int>& leaf){
        if(root==nullptr) return;
        inorder(root->left,leaf);
        if(root->left ==nullptr && root->right==nullptr) leaf.push_back(root->val);
        inorder(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;
        inorder(root1,t1);
        inorder(root2,t2);
        int n1=t1.size();
        int n2=t2.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            if(t1[i]!=t2[i]) return false;
        }
        return true;
    }
};