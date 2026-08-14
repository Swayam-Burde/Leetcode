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
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent_map[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_map[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};
        if (k == 0) return {target->val};

        unordered_map<TreeNode*, TreeNode*> parent_map;
        mapParents(root, parent_map);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        int current_distance = 0;

        while (!q.empty()) {
            int size = q.size();
            if (current_distance == k) break;
            current_distance++;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent_map.count(curr) && !visited[parent_map[curr]]) {
                    visited[parent_map[curr]] = true;
                    q.push(parent_map[curr]);
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

// Time Complexity
// Best Case:O(1)
// Average Case: O(N)
// Worst Case: O(N^2)

// Space Complexity
// Best Case: O(1)
// Average Case: O(N)
// Worst Case: O(N)