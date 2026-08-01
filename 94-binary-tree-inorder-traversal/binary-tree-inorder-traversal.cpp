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
    // USING MORRIS TRAVERSAL TECHNIQUE
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode * curr=root;

        while(curr!=NULL){
            // 1ST CASE
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }

            // 2ND CASE
            else{
                TreeNode * prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }

                // WHEN REACHED THE RIGHTMOST LEFT SUBTREE NODE
                if(prev->right==NULL){
                    prev->right=curr;   // CREATED THE THREAD
                    curr=curr->left;
                }
                
                // ALREADY CONNECTED REMOVE THE CONNECTION
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};