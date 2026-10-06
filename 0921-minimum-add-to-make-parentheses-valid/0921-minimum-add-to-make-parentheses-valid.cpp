class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty() || st.top() == ')'){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                }
            }
        }
        cnt += st.size();
        return cnt;
    }
};