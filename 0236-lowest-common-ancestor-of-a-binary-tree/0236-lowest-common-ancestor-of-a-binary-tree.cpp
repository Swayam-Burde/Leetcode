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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};

// Space Complexity
// Best Case: O(1)
// Average Case: O(log N)
// Worst Case: O(N)

// Time Complexity
// Best Case: O(1)
// Average Case: O(N)
// Worst Case: O(N)