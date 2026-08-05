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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* prev;
    TreeNode* last;
    
    void inorder(TreeNode* root){
        if(!root)   
            return ;
        inorder(root->left);

        // now check the nodes in increasing order
        if(prev!=NULL && root->val<prev->val){
            // THIS IS 1ST VOILATION 
            // MAKE THESE NODES FIRST AND MIDDLE
            if(first==NULL){
                first=prev;
                middle=root;
            }

            // THIS IS 2ND VOILATION 
            // MARK THIS NODE AS LAST
            else
                last=root;
        }

        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN); // THE PREVIOUS VALUE AT STARTING WILL BE MIN
        inorder(root);
        if(first && last)   
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};