/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markparents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>& parent_track,TreeNode*target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        // MARK PARENT OF EACH NODE 
        markparents(root,parent_track,target);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int currlevel=0;    // to check if distance became equal to k
        
        while(!q.empty()){
            int s=q.size();
            if(currlevel++ == k)    break;  // checking distance
            for(int i=0;i<s;i++){
                TreeNode * node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }
            }
        }
        // now store the remaining queue nodes in a list to return 
        vector<int>res;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};