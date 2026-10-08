class Solution {
public:
    void dfs(const string& s, int index, int remL, int remR, int openCount, string curr, unordered_set<string>& res) {
        if (openCount < 0) return;

        if (index == s.length()) {
            if (remL == 0 && remR == 0 && openCount == 0) {
                res.insert(curr);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            if (remL > 0) {
                dfs(s, index + 1, remL - 1, remR, openCount, curr, res);
            }
            dfs(s, index + 1, remL, remR, openCount + 1, curr + c, res);
        } else if (c == ')') {
            if (remR > 0) {
                dfs(s, index + 1, remL, remR - 1, openCount, curr, res);
            }
            dfs(s, index + 1, remL, remR, openCount - 1, curr + c, res);
        } else {
            dfs(s, index + 1, remL, remR, openCount, curr + c, res);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) remL--;
                else remR++;
            }
        }

        unordered_set<string> uniqueRes;
        dfs(s, 0, remL, remR, 0, "", uniqueRes);
        return vector<string>(uniqueRes.begin(), uniqueRes.end());
    }
};