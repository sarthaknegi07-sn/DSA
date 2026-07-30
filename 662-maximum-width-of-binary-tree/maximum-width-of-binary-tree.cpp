/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,long long>>q;    // THIS WILL STORE (NODE,INDEX)
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            long long mind=q.front().second;
            long long first,last;
            for(int i=0;i<s;i++)
            {
                long long currid =q.front().second-mind;
                TreeNode * node=q.front().first;
                q.pop();
                if(i==0)    first=currid;
                if(i==s-1)  last=currid;
                if(node->left)  q.push({node->left,currid*2+1});
                if(node->right) q.push({node->right,currid*2+2});
            }
            ans=max(ans,(int)(last-first+1));
        }
        return ans;
    }
};