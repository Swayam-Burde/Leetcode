class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        int minel = nums[0];
        int maxel = nums.back();
        for(int i = minel + 1; i <= maxel - 1; i++){
            if(st.count(i) == 0) ans.push_back(i);
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