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
    vector<int> nums;
    void preorder(TreeNode* root,int num){
        if(root==nullptr) return;
        num=num<<1 | root->val;
        if(root->right==nullptr && root->left==nullptr){
            nums.push_back(num);
            return;
        }
        preorder(root->left,num);
        preorder(root->right,num);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        int sum=0;
        for(int x:nums) sum+=x;
        return sum;
    }
};