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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy(0,head);
        ListNode* fast=head->next;
        ListNode* slow=head;
        ListNode* prev=&dummy;

        while(fast!=nullptr && slow!=nullptr){
            slow->next=fast->next;
            fast->next=slow;
            prev->next=fast;

            prev=slow;
            slow=slow->next;
            if(slow==nullptr) break;
            fast=slow->next;
        }
        return dummy.next;
    }
};