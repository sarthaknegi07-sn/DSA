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

    int maxi=INT_MIN;

    int findMax(TreeNode* root){
        if(root==NULL)
            return 0;
        
        //-VE KO ADD KRKE SUM GHAT JAEGA TO USSE 0 KRDO
        int l=max(0,findMax(root->left));   
        int r=max(0,findMax(root->right));

        maxi=max(maxi,l+r+root->val);

        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        findMax(root);
        return maxi;
    }
};