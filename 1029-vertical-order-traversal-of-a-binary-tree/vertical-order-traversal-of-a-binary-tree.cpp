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
    vector<vector<int>>ds;  // it will contain node->val,x,y

    void assigncord(TreeNode* root,int x,int y){
        if(root==NULL)
            return;
        ds.push_back({root->val,x,y});
        assigncord(root->left,x+1,y-1);
        assigncord(root->right,x+1,y+1);

        return ;
    }

    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[2] != v2[2])
            return v1[2] <v2[2];
        if(v1[1] != v2[1])
            return v1[1] <v2[1];
        return v1[0]<v2[0];
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        assigncord(root,0,0);
        // now all the nodes have been inserted into ds with coordinate values

        sort(ds.begin(),ds.end(),comp);
        // now they have been sorted in incresing order of y coordinate

        // now add them properly in a list of lists
        vector<vector<int>>ans;
        int prevcol=INT_MIN;
        for(auto node:ds){
            int value=node[0];
            int col=node[2];

            if(prevcol!=col){
                ans.push_back({});
                prevcol=col;
            }
            ans.back().push_back({node[0]});
        }

        return ans;
    }
};