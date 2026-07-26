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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;

        if(root==NULL)
            return res;

        st.push(root);
        while(!st.empty()){
            TreeNode* x=st.top();
            st.pop();
            if(x->right)
                st.push(x->right);
            if(x->left)
                st.push(x->left);
            res.push_back(x->val);
        }
        return res;
    }
};