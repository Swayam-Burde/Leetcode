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
    int leftHeight(TreeNode* root){
        if(root == NULL) return 0;
        int height = 0;
        while(root != NULL){
            height++;
            root = root -> left;
        }
        return height;
    }
    int rightHeight(TreeNode* root){
        if(root == NULL) return 0;
        int height = 0;
        while(root != NULL){
            height++;
            root = root -> right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

// Time Complexity
// Best Case: O(log N)
// Average Case: O(log^2 N)
// Worst Case: O(log^2 N)

// Space Complexity
// Best Case: O(1)
// Average Case: O(log N)
// Worst Case: O(log N)