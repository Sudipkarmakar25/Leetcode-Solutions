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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       int d1=101;
       int d2=101;
       ListNode*dummyhead=new ListNode(0);
       ListNode* tail = dummyhead;
       
        while(list1!=NULL||list2!=NULL)
        {
            if(list1!=NULL){
           d1=list1->val;
       }
       else{
           d1=101;
       }
       if(list2!=NULL){
           d2=list2->val;
       }
       else{
           d2=101;
       }
        if(d1>=d2)
        {
            tail->next=list2;
            list2=list2->next;
            tail=tail->next;
        }
        else{
            tail->next=list1;
            list1=list1->next;
            tail=tail->next;
        }
        }
        return dummyhead->next;
    }
};