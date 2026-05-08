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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * p1=l1;
    ListNode * p2=l2;
    int carry=0;
    ListNode * dummy=new ListNode();
    ListNode * p3=dummy;
    while(p1!=nullptr && p2!=nullptr){
        int sum=p1->val+p2->val+carry;
        carry=sum/10;
        sum=sum%10;
        ListNode * node=new ListNode(sum);
        p3->next=node;
        p3=p3->next;
        p1=p1->next;
        p2=p2->next;
    }  
    while(p1!=nullptr){
        int sum=p1->val+carry;
        carry=sum/10;
        sum=sum%10;
        ListNode * node=new ListNode(sum);
        p3->next=node;
        p3=p3->next;
        p1=p1->next;
    }  
    while(p2!=nullptr){
        int sum=p2->val+carry;
        carry=sum/10;
        sum=sum%10;
        ListNode * node=new ListNode(sum);
        p3->next=node;
        p3=p3->next;
        p2=p2->next;
    }
    if(carry==1){
        ListNode * node=new ListNode(carry);
        p3->next=node;
    }
    return dummy->next;
    }
};
