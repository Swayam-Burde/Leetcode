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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node -> val);
            if(node -> left) q.push({node -> left, {x-1,y+1}});
            if(node -> right) q.push({node -> right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto k : mp){
            vector<int> col;
            for(auto l : k.second){
                col.insert(col.end(), l.second.begin(), l.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};


// Space Complexity
// Best Case = O(N)
// Average Case = O(N)
// Worst Case = O(N)

// Time Complexity
// Best Case = O(N logN)
// Average Case = O(N logN)
// Worst Case = O(N logN)