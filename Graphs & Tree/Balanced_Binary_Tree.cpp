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
int height(TreeNode* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int ans=max(leftheight,rightheight)+1;
    return ans;
}
    bool isBalanced(TreeNode* root) {
       if(root==NULL) return true;
        int l=height(root->left);
        int r=height(root->right);
     bool ans=(abs(l-r)<=1);
        bool ll=isBalanced(root->left);
        bool rr=isBalanced(root->right);
        if(ans && ll && rr) return true;
        else return false;
    }
};