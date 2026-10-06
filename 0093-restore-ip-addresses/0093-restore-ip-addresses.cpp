class Solution {
public:
    bool valid(string& segment){
        if(segment.length() > 1 && segment[0] == '0'){
            return false;
        }
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
    void solve(int start, string& s, vector<string>& ans, vector<string>& curr){
        if(curr.size() == 4){
            if(start == s.length()){
                ans.push_back(curr[0] + '.' + curr[1] + '.' + curr[2] + '.' + curr[3]);
            }
            return;
        }
        int seg = 4 - curr.size();
        int chars = s.length() - start;
        if(chars < seg || chars > seg*3){
            return;
        }
        for(int i = 1; i <= 3 && start + i <= s.length(); i++){
            string segment = s.substr(start, i);
            if(valid(segment)){
                curr.push_back(segment);
                solve(start + i, s, ans, curr);
                curr.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length() < 4 || s.length() > 12) return ans;
        vector<string> curr;
        solve(0,s,ans,curr);
        return ans;
    }
};