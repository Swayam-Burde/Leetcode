class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2; i <= s.size(); i++){
            int curr = 0;
            int one = s[i-1] - '0';
            if(one >= 1 && one <= 9){
                curr += prev1;
            }
            int two = (s[i-2] -'0') * 10 + s[i-1] - '0';
            if(two >= 10 && two <= 26){
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};