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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p  == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p -> val != q -> val) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};


// N = number of nodes of p
// M = number of nodes of q
// Space Complexity = O(1)
// Time Complexity = O(min(N,M))

// Best Case = O(1)
// Average Case = O(min(N,M))
// Worst Case = O(min(N,M))