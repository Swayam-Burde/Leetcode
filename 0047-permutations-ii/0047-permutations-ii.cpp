class Solution {
public:
    void generate(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int j = i; j < nums.size(); j++){
            if(st.find(nums[j]) != st.end()){
                continue;
            }
            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            generate(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(0,nums,ans);
        return ans;
    }
};