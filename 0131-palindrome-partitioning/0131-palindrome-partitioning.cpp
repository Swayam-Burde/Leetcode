class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();   
        vector<vector<vector<string>>> dp(n + 1);
        dp[n] = {{}};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    string sub = s.substr(i, j - i + 1);
                    for ( auto& part : dp[j + 1]) {
                        vector<string> currentPart;
                        currentPart.push_back(sub);
                        currentPart.insert(currentPart.end(), part.begin(), part.end());
                        dp[i].push_back(currentPart);
                    }
                }
            }
        }
        return dp[0];
    }
};