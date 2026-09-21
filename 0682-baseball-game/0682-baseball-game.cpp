class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> ans;
        for(int i = 0; i < n ; i++){
            if(operations[i] == "C"){
                ans.pop_back();
            }
            else if(operations[i] == "D"){
                ans.push_back(2*ans.back());
            }
            else if(operations[i] == "+"){
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            }
            else{
                ans.push_back(stoi(operations[i]));
            }
        }
        return accumulate(ans.begin(),ans.end(), 0);
    }
};