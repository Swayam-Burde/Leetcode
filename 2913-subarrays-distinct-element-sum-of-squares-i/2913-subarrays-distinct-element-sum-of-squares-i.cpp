class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            vector<bool> seen(101, false);
            for(int j = i; j < n; j++){
                if(!seen[nums[j]]){
                    seen[nums[j]] = true;
                    cnt++;
                }
                sum += cnt*cnt;
            }
        }
        return sum;
    }
};