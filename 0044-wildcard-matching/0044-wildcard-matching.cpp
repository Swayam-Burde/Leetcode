class Solution {
public:
    bool isAllStar(const string &p, int k) {
        for (int j = 1; j <= k; j++) {
            if (p[j - 1] != '*') {
                return false;
            }
        }
        return true;
    } 

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            dp[0][j] = isAllStar(p, j);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};