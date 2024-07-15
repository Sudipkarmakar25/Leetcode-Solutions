#include <bits/stdc++.h>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>chk;
        for(int i=0;i<nums.size();i++)
        {
            chk[nums[i]]=10;
        }
        ListNode* first=NULL;
        ListNode* current=NULL;
        bool ff=false;
        while(head!=NULL)
        {
            if(chk[head->val]!=10)
            { 
                if(!ff){
                first=new ListNode(head->val);
                current=first;
                ff=true;
                }
                else{
                    current->next=new ListNode(head->val);
                    current = current->next;
                }
            }
            head=head->next;
        }
        return first;
    }
};