class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefSum;
        int cnt = 0;
        prefSum[0] = 1;
        int sum = 0;
        for(int i : nums){
            sum += i;
            int target = sum - k;
            if(prefSum.find(target) != prefSum.end()){
                cnt += prefSum[target];
            }
            prefSum[sum]++;
        }
        return cnt;    
    }
};