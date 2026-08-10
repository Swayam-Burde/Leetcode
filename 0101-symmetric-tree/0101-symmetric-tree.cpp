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
    bool sym(TreeNode* l, TreeNode* r){
        if(l == NULL || r == NULL){
            return l == r;
        }
        if(l -> val != r -> val) return false;
        return sym(l ->left, r -> right) && sym(l -> right, r -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || sym(root -> left, root -> right);
    }
};

// Space Complexity
// Best Case: O(1)
// Average Case: O(logN)
// Worst Case: O(N)

// Time Complexity
// Best Case: O(1)
// Average Case: O(N)
// Worst Case: O(N)