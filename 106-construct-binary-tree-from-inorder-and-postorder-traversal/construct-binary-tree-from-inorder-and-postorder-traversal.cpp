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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int i=0;
        for(auto it:inorder){
            mp[it]=i++;
        }

        TreeNode* root=buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);

        return root;
    }

    TreeNode* buildtree(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mp){
        if(poststart > postend || instart > inend)
            return NULL;
        
        TreeNode * root=new TreeNode(postorder[postend]);

        int inroot=mp[root->val];
        int numsleft=inroot-instart;

        root->left=buildtree(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);

        root->right=buildtree(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mp);

        return root;
    }
};