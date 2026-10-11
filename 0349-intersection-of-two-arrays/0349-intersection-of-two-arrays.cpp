class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st(nums1.begin(),nums1.end());
        for(int x : nums2){
            if(st.erase(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};