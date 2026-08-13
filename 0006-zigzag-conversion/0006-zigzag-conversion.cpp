class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }
        string result;
        result.reserve(s.length());
        int n = s.length();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += cycleLen) {
                result += s[j];
                int secondIndex = j + cycleLen - 2 * i;
                if (i != 0 && i != numRows - 1 && secondIndex < n) {
                    result += s[secondIndex];
                }
            }
        }
        return result;
    }
};