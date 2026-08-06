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

    class Nodevalue{
    public:
        int minnode;
        int maxnode;
        int maxsize;
        int sum;

        Nodevalue(int mn,int mx,int sz,int sm){
            minnode=mn;
            maxnode=mx;
            maxsize=sz;
            sum=sm;
        }
    };

    int ans=0;

    Nodevalue largestsum(TreeNode* root){

        // Empty tree is a BST
        if(!root)
            return Nodevalue(INT_MAX,INT_MIN,0,0);

        // Get information from left and right subtree
        auto left=largestsum(root->left);
        auto right=largestsum(root->right);

        // Current subtree is BST
        if(left.maxnode < root->val && root->val < right.minnode){

            int currsum=left.sum+right.sum+root->val;
            ans=max(ans,currsum);

            return Nodevalue(
                min(left.minnode,root->val),
                max(right.maxnode,root->val),
                left.maxsize+right.maxsize+1,
                currsum
            );
        }

        // Current subtree is not BST
        // Return invalid range so parent can never become BST
        return Nodevalue(
            INT_MIN,
            INT_MAX,
            max(left.maxsize,right.maxsize),
            0
        );
    }

    int maxSumBST(TreeNode* root) {

        largestsum(root);

        return ans;
    }
};