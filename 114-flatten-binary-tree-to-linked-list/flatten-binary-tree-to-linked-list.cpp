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

    void findpreorder(TreeNode* root,vector<TreeNode*>& preorder){
        if(root==NULL)
            return;
        preorder.push_back(root);
        findpreorder(root->left,preorder);
        findpreorder(root->right,preorder);
    }

    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        //  FIND THE PREORDER TRAVERSAL
        vector<TreeNode*>preorder;  // now it stores all the address of the values of original tree
        findpreorder(root,preorder);

        for(int i=0;i<preorder.size()-1;i++){
            preorder[i]->left=NULL;
            preorder[i]->right=preorder[i+1];
        }
        // add last value
        preorder[preorder.size()-1]->left=NULL;
        preorder[preorder.size()-1]->right=NULL;
    }
};