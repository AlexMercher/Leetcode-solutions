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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* groupPrev=&dummy;
        while(true){
            ListNode* kth=groupPrev;
            for(int i=0;i<k;i++){
                kth=kth->next;
                if(kth==nullptr) return dummy.next;
            }

            ListNode* groupNext=kth->next;

            ListNode* prev=groupNext;
            ListNode* curr=groupPrev->next;
            while(curr!=groupNext){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }

            ListNode* temp=groupPrev->next;
            groupPrev->next=kth;
            groupPrev=temp;
        }
    }
};