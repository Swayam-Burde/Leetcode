class Solution {
public:
    vector<string> ans;
    void remove(string s, int start, int lastRemove, char open, char close) {
        int balance = 0;
        for (int i = start; i < s.size(); i++) {
            if (s[i] == open)
                balance++;
            else if (s[i] == close)
                balance--;
            if (balance < 0) {
                for (int j = lastRemove; j <= i; j++) {
                    if (s[j] == close &&
                        (j == lastRemove || s[j - 1] != close)) {
                        string next = s.substr(0, j) + s.substr(j + 1);
                        remove(next, i, j, open, close);
                    }
                }
                return;
            }
        }
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if (open == '(') {
            remove(reversed, 0, 0, ')', '(');
        } else {
            ans.push_back(reversed);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        remove(s, 0, 0, '(', ')');
        return ans;
    }
};