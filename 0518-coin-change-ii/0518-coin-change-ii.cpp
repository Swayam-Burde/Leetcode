class Solution {
public:
    int ways(int ind, int t, vector<int>& coins, vector<vector<int>>& dp){
        if (ind == 0) return (t % coins[0] == 0);
        if(dp[ind][t] != -1) return dp[ind][t];
        int notTake = ways(ind - 1, t, coins, dp);
        int take = 0;
        if(coins[ind] <= t) take = ways(ind, t - coins[ind], coins, dp);
        return dp[ind][t] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return ways(coins.size() - 1, amount, coins, dp);
    }
};