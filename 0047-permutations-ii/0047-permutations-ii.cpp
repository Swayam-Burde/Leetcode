class Solution {
public:
    void generate(int i, vector<int>& nums, set<vector<int>>& ans){
        if(i == nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                generate(i+1,nums,ans);
            }else{
                swap(nums[i],nums[j]);
                generate(i+1,nums,ans);
                swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        generate(0,nums,ans);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};