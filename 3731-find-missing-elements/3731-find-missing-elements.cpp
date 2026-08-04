class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> el(nums.begin(), nums.end());
        int minel = *min_element(nums.begin(), nums.end());
        int maxel = *max_element(nums.begin(), nums.end());
        for(int i = minel; i <= maxel; i++){
            if(el.find(i) == el.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Space Complexity
// Best Case = O(1)
// Average Case = O(N)
// Worst Case = O(N)

// Time Complexity
// Best Case = O(N + M)
// Aerage Case = O(N + M)
// Worst Case = O(N^2 + N * M)