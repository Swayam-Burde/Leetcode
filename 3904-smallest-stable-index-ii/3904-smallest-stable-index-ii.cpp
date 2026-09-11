class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minel(n);
        minel[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            minel[i] = min(nums[i],minel[i+1]);
        }
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            int diff = maxi - minel[i];
            if(diff <= k) return i;
        }
        return -1;
    }
};