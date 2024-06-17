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
int findlength(ListNode*&head)
{
    int len=0;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=findlength(head);
        if(head==NULL) return NULL;
        if(k>len)
        {
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=curr->next;
        int cnt=0;
        while(cnt<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            cnt++;
        }
        if(forward!=NULL)
        {
            head->next=reverseKGroup(forward,k);
        }
        return prev;
    }
};