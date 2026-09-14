class Solution {
public:
    bool solve(int i, int j, string& s, string& p){
        if(i < 0 && j < 0){
            return true;
        }
        if(j < 0){
            return false;
        }

        if(i >= 0 && s[i] == p[j]){
            return solve(i-1, j- 1, s, p);
        }
        else if(i >= 0 && p[j] == '.'){
            return solve(i-1, j-1,s,p);
        }
        else if(p[j] == '*') {
            bool notTake = solve(i, j - 2, s, p);
            bool take = false;
            if(i >= 0 && (s[i] == p[j - 1] || p[j - 1] == '.')) {
                take = solve(i - 1, j, s, p);
            }

            return notTake || take;
        }

        return false;
    }
    bool isMatch(string s, string p) {
        return solve(s.size()-1,p.size()-1,s,p);
    }
};