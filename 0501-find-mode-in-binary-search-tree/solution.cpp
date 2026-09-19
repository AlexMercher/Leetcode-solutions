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
    int prev=-1;
    int currcount=0;
    int maxcount=0;
    bool first=true;
    vector<int> ans;
    void inorder(TreeNode* root){//Inorder traversal to count in the ascending order.
        if(root==nullptr) return;
        inorder(root->left);
        if(first || root->val!=prev){
            first=false;
            prev=root->val;
            currcount=1;
        }else{
            currcount++;
        }
        if(currcount>maxcount){
            maxcount=currcount;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(currcount==maxcount){
            ans.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};