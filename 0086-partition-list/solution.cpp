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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* less=&lessDummy;
        ListNode* great=&greaterDummy;

        while(head!=nullptr){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                great->next=head;
                great=great->next;
            }
            head=head->next;
        }
        less->next=greaterDummy.next;
        great->next=nullptr;
        return lessDummy.next;
    }
};