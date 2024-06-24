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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        vector<double>ans;
        ans.push_back(root->val);
        while(!q.empty())
        {
            if(q.front()==NULL)
            {
                q.pop();
                double s=0;
                if(temp.size()>0){
                for(int i=0;i<temp.size();i++)
                {
                    cout<<temp[i]<<" ";
                 s+=temp[i];
                }
                ans.push_back(s/(temp.size()*1.00000));
                }
                if(!q.empty())
                {
                q.push(NULL);
                }
                temp.clear();
                cout<<endl;
            }
            else{
                TreeNode* req=q.front();
                if(req->left!=NULL)
                {
                    q.push(req->left);
                    temp.push_back(req->left->val);
                }
                if(req->right!=NULL)
                {
                    q.push(req->right);
                    temp.push_back(req->right->val);
                }
                q.pop();
            }

        }
        return ans;

    }
};