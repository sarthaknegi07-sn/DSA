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
    void inordering(TreeNode* root,vector<int>& inorder){
        if(root==NULL)  return;
        inordering(root->left,inorder);
        inorder.push_back(root->val);
        inordering(root->right,inorder);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inordering(root,inorder);
        int n=inorder.size();
        int l=0,r=n-1;
        while(l<r){
            if(inorder[l]+inorder[r]==k)
                return true;
            else if(inorder[l]+inorder[r]>k)
                r--;
            else
                l++;
        }
        return false;
    }
};