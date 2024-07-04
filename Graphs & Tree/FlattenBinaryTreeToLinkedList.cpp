#include <bits/stdc++.h>
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
    void solve(TreeNode* root, vector<int>& req) {
        if (root == NULL) return;
        req.push_back(root->val);
        solve(root->left, req);
        solve(root->right, req);
    }

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        vector<int> req;
        solve(root, req);

        TreeNode* current = root;
        current->val = req[0];
        current->left = nullptr;

        for (int i = 1; i < req.size(); ++i) {
            current->right = new TreeNode(req[i]);
            current = current->right;
        }
    }
};
