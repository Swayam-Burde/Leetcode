class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i : nums1){
            mp[i]++;
        }
        for(int x : nums2){
            if(mp[x] > 0){
                mp[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};