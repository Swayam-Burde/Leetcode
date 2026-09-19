class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum = -DBL_MAX;
        double sum = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            if(j-i+1 == k){
                maxsum = max(maxsum, sum);
                sum -= nums[i];
                i++;
            }
        }
        return maxsum / k;
    }
};