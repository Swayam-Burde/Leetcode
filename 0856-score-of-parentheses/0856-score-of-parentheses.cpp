class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt = 0;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                st.pop();
                if(s[i-1] == '('){
                    cnt += (1 << st.size());
                }
            }
        }
        return cnt;
    }
};