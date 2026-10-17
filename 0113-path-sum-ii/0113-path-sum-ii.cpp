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
    void traversal(TreeNode* root, int remaining, vector<int>& path, vector<vector<int>>& ans){
        if(root == NULL) return;
        path.push_back(root -> val);
        remaining -= root ->val;
        if(root -> right == NULL && root -> left == NULL && remaining == 0){
            ans.push_back(path);
        }
        else{
            traversal(root -> left, remaining, path, ans);
            traversal(root -> right, remaining, path, ans);
        }
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        traversal(root, targetSum, path, ans);
        return ans;
    }
};