/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode* head,ListNode* tail){
        if(head==nullptr || head==tail) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;

        while(fast!=nullptr && fast!=tail && fast->next!=nullptr && fast->next!=tail){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* RightHead=slow->next;
        TreeNode* root=new TreeNode(slow->val);
        if(prev!=nullptr) prev->next=nullptr;
        root->left=solve(head,slow);
        root->right=solve(RightHead,tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        return solve(head,nullptr);
    }
};