#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class Solution {
public:
    void solve(TreeNode* root, map<int, int>& req, int dis) {
        if (root == NULL)
            return;
        if(req.find(abs(dis))==req.end()) req[abs(dis)] = root->val;
        solve(root->right, req, dis + 1);
        solve(root->left, req, dis +1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> req;
        vector<int> ans;

        solve(root, req, 0);

        for (auto x : req) {
            cout<<x.first<<" "<<x.second<<endl;
            ans.push_back(x.second);
        }
        return ans;
    }
};