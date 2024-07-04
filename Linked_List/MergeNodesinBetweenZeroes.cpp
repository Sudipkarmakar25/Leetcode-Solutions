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
    ListNode* mergeNodes(ListNode* head) {
        int cnt = 0;
        head = head->next;
        ListNode* newList;
        ListNode* prev = NULL;
        while (head != NULL) {
            if (head->val != 0) {
                cnt += head->val;
            } else {
                ListNode* newNode = new ListNode(cnt);
                if (prev == NULL) {
                    newList = newNode;
                    prev = newNode;
                }
                if (prev != NULL)
                    prev->next = newNode;
                prev = newNode;
                cnt = 0;
            }
            head = head->next;
        }
        if (prev != NULL)
            prev->next = NULL;
        return newList;
    }
};