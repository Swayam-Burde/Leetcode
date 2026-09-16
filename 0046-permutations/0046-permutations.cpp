class Solution {
public:
    int fact(int n){
        int a = 1;
        for(int i = 1; i <= n; i++){
            a *= i;
        }
        return a;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < fact(nums.size()); i++){
            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};