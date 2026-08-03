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

    // IN THIS WE COPY LEFT SUBTREE OF ROOT AND WE MOVE TO THE RIGHTEST OF RIGHT SUBTREE OF ROOT AND THEN JOIN COPIED LEFT SUBTREE. 
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)
            return root->right;
            
        if(root->right==NULL)
            return root->left;
        
        TreeNode* lastright=root->left;
        TreeNode* rightchild=root->right;

        // move to the rightmost node of right subtree
        while(rightchild->left!=NULL)
            rightchild=rightchild->left;
        
        rightchild->left=lastright;

        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) 
            return NULL;

        if(root->val==key){
            return helper(root);
        }

        TreeNode* newhead=root;

        while(root){
            if(root->val<key){
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                root=root->right;
            }
            else{
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                root=root->left;
            }
        }
        return newhead;
    }
};