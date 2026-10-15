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
    void dfs(TreeNode* root, int& depth, int curr){
        if(root == NULL){
            curr--;
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            depth = min(depth, curr);
        }
        dfs(root -> left, depth, curr+1);
        dfs(root -> right, depth, curr+1);
    }
    int minDepth(TreeNode* root) {
        int depth = INT_MAX;
        int curr = 1;
        if(root == NULL) return 0;
        dfs(root, depth, curr);
        return depth;
    }
};