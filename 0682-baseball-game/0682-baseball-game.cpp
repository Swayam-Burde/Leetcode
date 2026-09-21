class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> ans;
        int res = 0;
        for(int i = 0; i < n ; i++){
            if(operations[i] == "C"){
                res -= ans.back();
                ans.pop_back();
            }
            else if(operations[i] == "D"){
                res += (2*ans.back());
                ans.push_back(2*ans.back());
            }
            else if(operations[i] == "+"){
                res += ans[ans.size()-1] + ans[ans.size()-2];
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            }
            else{
                ans.push_back(stoi(operations[i]));
                res += ans.back();
            }
        }
        return res;
    }
};