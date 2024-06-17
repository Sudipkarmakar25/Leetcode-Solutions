#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>freq;
        int chk=0;
        while(head!=NULL)
        {
            freq[head]++;
            if(freq[head]>1)
            {
                chk=1;
                break;
            }
            head=head->next;
        }
        if(chk==0) return false;
        else return true;
    }
};