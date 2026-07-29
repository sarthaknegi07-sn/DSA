/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool fn(TreeNode* root, int k,vector<TreeNode*>&res){
        if(root==NULL)
            return false;
        res.push_back(root);
        if(root->val==k)
            return true;
        if(fn(root->left,k,res) || fn(root->right,k,res))
            return true;
        res.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return {};

        // find the route of both p and q nodes from root node
        vector<TreeNode*>res1;
        vector<TreeNode*>res2;
        fn(root,p->val,res1);
        fn(root,q->val,res2);

        // now iterate in both the arrays 
        int i=0;
        while(i<res1.size() && i<res2.size() && res1[i]==res2[i])
            i++;
        return res1[i-1];
    }
};