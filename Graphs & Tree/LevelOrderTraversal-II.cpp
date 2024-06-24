#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> ans;

         if(root==NULL)
        {
            return ans;
        }
        vector<int> temp;

        if (root != NULL) {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.clear();
        }

        while (!q.empty()) {
            if (q.front() == NULL ) {
                if(temp.size()>0) ans.push_back(temp);
                temp.clear();
                q.pop();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            } else {
                TreeNode* req = q.front();
                if (req->left != NULL) {
                    q.push(req->left);
                    temp.push_back(req->left->val);
                }
                if (req->right != NULL) {
                    q.push(req->right);
                    temp.push_back(req->right->val);
                }
                q.pop();
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};