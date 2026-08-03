class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp = piles;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                dp[i] = max(piles[i] - dp[i+1], piles[j] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};

// Time Complexity = O(N^2)
// Space Complexity = O(N)


// Best Case = O(N^2)
// Average Case = O(N^2)
// Worst Case = O(N^2)