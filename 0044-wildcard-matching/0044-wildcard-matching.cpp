class Solution {
public:
    bool f(string& s,int j){
        for(int i = j; i < s.size();i++){
            if(s[i] != '*'){
                return false;
            }
        }
        return true;
    }
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == s.size()) {
            return f(p, j);
        }
        if (j == p.size()) {
            return false;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (i < s.size() && s[i] == p[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s, p,dp);
        } else if ( i < s.size() && p[j] == '?') {
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
        } else if (i < s.size() && p[j] == '*') {
            return dp[i][j] = solve(i, j + 1, s, p, dp)  || solve(i+1,j,s,p, dp);
        } 
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(0, 0, s, p,dp);
    }
};