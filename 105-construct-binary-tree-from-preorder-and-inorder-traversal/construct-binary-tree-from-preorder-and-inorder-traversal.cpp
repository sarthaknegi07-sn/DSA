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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int i=0;
        for(auto it:inorder){
            mp[it]=i++;
        }

        TreeNode* root=buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

        return root;
    }

    TreeNode* buildtree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mp){
        if(prestart > preend || instart > inend)
            return NULL;
        
        TreeNode * root=new TreeNode(preorder[prestart]);

        int inroot=mp[root->val];
        int numsleft=inroot-instart;

        root->left=buildtree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mp);

        root->right=buildtree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mp);

        return root;
    }
};