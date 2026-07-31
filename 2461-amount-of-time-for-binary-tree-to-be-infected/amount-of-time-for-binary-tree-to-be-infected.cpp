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

    void getparent(TreeNode* root, int start,unordered_map<TreeNode*,TreeNode*>& parent_track,TreeNode*& target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start)    
                target=node;
            if(node->left){
                parent_track[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        // first find parent and start node pointer

        unordered_map<TreeNode*,TreeNode*>parent_track;
        TreeNode * target=nullptr;
        getparent(root,start,parent_track,target);

        // now we have got target node so start the bfs from target
    
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int maxi=0;

        // start BFS
        while(!q.empty()){
            int s=q.size();
            int j=0;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                // track left child
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                    j=1;
                }
                // track right child
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                    j=1;
                }
                // track parent child
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                    j=1;
                }
            }
            if(j==1)
                maxi++;
        }
        return maxi;
    }
};