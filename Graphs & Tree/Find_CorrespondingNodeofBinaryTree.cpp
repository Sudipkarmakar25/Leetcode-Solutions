#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* solve(TreeNode* cloned, int n) {
        if (cloned == NULL) {
            return NULL;
        }
        if (cloned->val == n) {
            return cloned;
        }
        TreeNode* leftResult = solve(cloned->left, n);
        if (leftResult != NULL) {
            return leftResult;
        }
        return solve(cloned->right, n);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        int value = target->val;
        return solve(cloned, value);
    }
};