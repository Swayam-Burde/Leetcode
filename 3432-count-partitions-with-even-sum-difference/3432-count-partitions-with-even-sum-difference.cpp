class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int totalSum = 0;
        int curr = 0;
        for(int i : nums) totalSum += i;
        for(int i = 0; i < nums.size() - 1; i++){
            curr += nums[i];
            totalSum -= nums[i];
            if((totalSum - curr)% 2 == 0) cnt++;
        }
        return cnt;
    }
};