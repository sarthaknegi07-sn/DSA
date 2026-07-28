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
    vector<int>ds;      // STORES THE RIGHT VIEW    
    void revPreorder(TreeNode * root,int level){
        if(root==NULL)
            return;

        if(level==ds.size())
            ds.push_back(root->val);
        
        revPreorder(root->right,level+1);
        revPreorder(root->left,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        // RECURSIVE APPROACH 
        revPreorder(root,0);
        return ds;
    }
};