#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          map<ListNode*,int>freq;
        int chk=0;
       while(true)
       {
           if(headA!=NULL)
           {
               freq[headA]++;
               
           }
           if(headB!=NULL)
           {
               freq[headB]++;
           }
           
               if(freq[headB]>1)
               {
                   return headB;
               }
               else if(freq[headA]>1)
               {
               return headA;
               }
        
           if(headA!=NULL)
           {
              headA=headA->next;
               
           }
           if(headB!=NULL)
           {
              headB=headB->next;
           }
           if(headA==NULL && headB==NULL)
           {
               return NULL;
           }
       }
    }
};