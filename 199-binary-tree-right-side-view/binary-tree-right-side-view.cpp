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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        
        // PERFORM LEVEL ORDER TRAVERSAL
        queue<TreeNode *>q;
        vector<vector<int>>res;

        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
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

        // NOW ONLY TAKE THE LAST NODE OF EVERY LEVEL
        vector<int>ans;
        for(auto it:res){
            ans.push_back(it[it.size()-1]);
        }

        return ans;
    }
};