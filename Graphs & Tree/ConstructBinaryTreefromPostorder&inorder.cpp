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
int findPosition(vector<int>& inorder,int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==element) return i;
    }
    return -1;
}
TreeNode* Solve(vector<int>& inorder, vector<int>& postorder,int size,int &postindex,int inorderstart,int inorderend)
{
    if(postindex<0 || inorderstart>inorderend) return NULL;
    int element=postorder[postindex--];
    TreeNode* root= new TreeNode(element);
    int pos=findPosition(inorder,size,element);
    root->right=Solve(inorder,postorder,size,postindex,pos+1,inorderend);
     root->left=Solve(inorder,postorder,size,postindex,inorderstart,pos-1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int postindex=size-1;
        return Solve(inorder,postorder,size,postindex,0,size-1);
    }
};