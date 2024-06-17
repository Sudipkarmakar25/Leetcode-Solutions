#include<bits/stdc++.h>
using namespace std;
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
 
    ListNode *detectCycle(ListNode *head) {
         map<ListNode*,int>freq;
         int cnt=0;
         while(head!=NULL)
         {
          freq[head]++;
          head=head->next;
          cnt++;
          if(freq[head]>1)
          {
              return head;
          }
         }
         return NULL;
    }
};