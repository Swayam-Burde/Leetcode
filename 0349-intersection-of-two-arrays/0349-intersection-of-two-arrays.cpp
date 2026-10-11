class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int i = 0; i < nums1.size(); i++){
            st1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size();i++){
            st2.insert(nums2[i]);
        }
        for(int num : st1){
            if(st2.find(num) != st2.end()){
                ans.push_back(num);
            }
        }
        return ans;
    }
};