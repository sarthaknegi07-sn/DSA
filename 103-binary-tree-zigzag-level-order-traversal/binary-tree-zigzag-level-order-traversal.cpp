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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        // FIND LEVEL ORDER

        queue<TreeNode*>q;
        vector<vector<int>>res;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>level;
            for(int i=0;i<s;i++){
                TreeNode * x=q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            res.push_back(level);
        }

        // NOW ON ODD INDEXES REVERSE THE ELEMENTS

        for(int i=0;i<res.size();i++){
            if(i%2!=0){     //ODD
                reverse(res[i].begin(),res[i].end());
            }
        }

        return res;
    }
};