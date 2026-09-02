class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                nums2.push_back(nums1[i]);
                cnt++;
            }
        }
        if(cnt == n){
            return true;
        }
        else{
            int j = 0;
            for(int i = 0; i < n; i++){
                if(nums1[i] % 2 == 0){
                    j = i;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                nums2.push_back(nums1[i] - nums1[j]);
            }
            return true;
        }
        return false;
    }
};