class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> st;
        int n = path.size();
        string seg;
        while(getline(ss,seg,'/')){
            if(seg == "" || seg == "."){
                continue;
            }
            if(seg == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(seg);
            }
        }
        string res = "";
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        return (res.empty() ? "/" : res); 
    }
};