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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next ==nullptr) return head;

        int n=1;
        ListNode* tail=head;
        while(tail->next!=nullptr){
            tail=tail->next;
            n++;
        }
        k%=n;
        if(k==0) return head;
        ListNode* newTail=head;
        for(int i=1;i<n-k;i++){
            newTail=newTail->next;
        }
        ListNode* newNode=newTail->next;
        newTail->next=nullptr;
        tail->next=head;
        return newNode;
    }
};