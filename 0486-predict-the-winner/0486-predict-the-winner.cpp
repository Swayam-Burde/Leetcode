class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                dp[i] = max(nums[i] - dp[i+1], nums[j] - dp[i]);
            }
        }
        return dp[0] >= 0;


    }
};

// Space Complexity = O(N)
// Time Complexity = O(N^2)

// Best Case = O(N^2)
// Average Case = O(N^2)
// Worst Case = O(N^2)