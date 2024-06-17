#include<bits/stdc++.h>
using namespace std;
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
ListNode*reverse(ListNode* head)
{
    ListNode*prev=NULL;
    ListNode*curr=head;
     ListNode*forward=head->next;
     while(curr!=NULL)
     {
         forward=curr->next;
         curr->next=prev;
         prev=curr;
         curr=forward;
     }
     return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        else if(head->next==NULL) return true;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode*reverseLLhead=reverse(slow->next);
        slow->next=reverseLLhead;
        ListNode*temp1=head;
        ListNode*temp2=reverseLLhead;
        while(temp2!=NULL)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};