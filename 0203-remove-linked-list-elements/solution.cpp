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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;

        ListNode* dup=head;
        ListNode* prev=nullptr;
        while(dup!=nullptr){
            if(dup->val==val){
                if(dup==head) head=dup->next;
                else prev->next=dup->next;
            }
            else prev=dup;
            dup=dup->next;
        }
        return head;
    }
};