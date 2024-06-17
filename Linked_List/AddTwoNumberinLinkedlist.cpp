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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry=0;
        int s=0;
        int digit=0;
        while(l1!=NULL ||  l2!=NULL||carry!=0)
        {
            int d1,d2;
            if(l1==NULL){
                d1=0;
            }
            else{
                d1=l1->val;
            }
            if(l2==NULL)
            {
                d2=0;
            }
            else{
                d2=l2->val;
            }
             s=d1+d2+carry;
             digit=s%10;
             carry=s/10;
            ListNode* newNode = new ListNode(digit);
            tail->next=newNode;
            tail=tail->next;
            if(l1!=NULL){
            l1=l1->next;
            }
            if(l2!=NULL){
            l2=l2->next;
            }

        }
        return dummyHead->next;
    }
};