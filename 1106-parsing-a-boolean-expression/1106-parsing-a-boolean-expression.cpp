class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> st;
        for (char c : expression) {
            if (c == ',' || c == '(') {
                continue;
            }
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push_back(c);
            } else if (c == ')') {
                bool hasTrue = false, hasFalse = false;
                while (st.back() == 't' || st.back() == 'f') {
                    if (st.back() == 't') hasTrue = true;
                    if (st.back() == 'f') hasFalse = true;
                    st.pop_back();
                }
                char op = st.back();
                st.pop_back(); 
                if (op == '!') {
                    st.push_back(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push_back(hasFalse ? 'f' : 't');
                } else if (op == '|') {
                    st.push_back(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.back() == 't';
    }
};