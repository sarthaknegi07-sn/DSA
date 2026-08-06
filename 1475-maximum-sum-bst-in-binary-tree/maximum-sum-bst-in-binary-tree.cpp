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
        if(!root)
            return Nodevalue(INT_MAX,INT_MIN,0,0);

        // get values from left and right subtree of the current tree
        auto left=largestsum(root->left);
        auto right=largestsum(root->right);

        // now check if curr node is greater than max in left and 
        // smaller than min in right

        // ITS A BST
        if(left.maxnode < root->val && root->val < right.minnode){
            int currsum=root->val+left.sum+right.sum;
            ans=max(ans,currsum);

            return Nodevalue(min(left.minnode,root->val),max(root->val,right.maxnode),left.maxsize+1+right.maxsize,currsum);
        }

        // OTHERWISE RETURN [INF,-INF] SO THAT PARENT CANT BE VALID BST
        return Nodevalue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize),0);
    }

    int maxSumBST(TreeNode* root) {
        // HERE WE WILL PERFORM POST ORDER TRSAVERSAL
        largestsum(root);
        return  ans; 
    }
};