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
TreeNode* Solve(vector<int>& preorder, vector<int>& inorder,int size,int &preIndex,int inorderStart,int inorderend)
{
if(preIndex>=size || inorderStart>inorderend) return NULL;
int element=preorder[preIndex++];
TreeNode* root=new TreeNode(element);
int pos=findPosition(inorder,size,element);

root->left=Solve(preorder,inorder,size,preIndex,inorderStart,pos-1);
root->right=Solve(preorder,inorder,size,preIndex,pos+1,inorderend);
return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int size=preorder.size();
        int preindex=0;
        return Solve(preorder,inorder,size,preindex,0,size-1);
    }
};