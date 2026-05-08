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
    ListNode* reverse(ListNode* head){
    ListNode * prev=nullptr;
    ListNode * curr=head;
    while(head!=nullptr){
        head=head->next;
        curr->next=prev;
        prev=curr;
        curr=head;
    } 
    return prev;
    }
    void reorderList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return;
    ListNode * slow=head;
    ListNode * fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* second=reverse(slow->next);
    slow->next=nullptr;
    ListNode * first=head;
    while(first!=nullptr && second!=nullptr){
        ListNode * t1=first->next;
        ListNode * t2=second->next;
        first->next=second;
        second->next=t1;
        first=t1;
        second=t2;
    }
    }
};
