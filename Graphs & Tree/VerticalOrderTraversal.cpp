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
    void solve(TreeNode* root, map<int, vector<pair<int, int>>>& req, int dis, int level) {
        if (root == nullptr) return;
        req[dis].push_back({level, root->val});
        solve(root->left, req, dis - 1, level + 1);
        solve(root->right, req, dis + 1, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> req;
        vector<vector<int>> ans;

        solve(root, req, 0, 0);

        for (auto& x : req) {
            sort(x.second.begin(), x.second.end());
            vector<int> column;
            for (auto& p : x.second) {
                column.push_back(p.second);
            }
            ans.push_back(column);
        }
        return ans;
    }
};