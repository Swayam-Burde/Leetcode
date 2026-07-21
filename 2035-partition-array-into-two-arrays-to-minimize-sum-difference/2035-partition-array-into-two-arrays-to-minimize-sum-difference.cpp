class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sz = 0, lSum = 0, rSum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sz++;
                    lSum += nums[i];
                    rSum += nums[i + n];
                }
            }
            left[sz].push_back(lSum);
            right[sz].push_back(rSum);
        }
        for (int sz = 0; sz <= n; ++sz) {
            sort(right[sz].begin(), right[sz].end());
        }
        int minDiff = INT_MAX;
        for (int k = 0; k <= n; ++k) {
            for (int a : left[k]) {
                int target = totalSum / 2 - a;
                auto& rVec = right[n - k];
                auto it = lower_bound(rVec.begin(), rVec.end(), target);
                if (it != rVec.end()) {
                    int b = *it;
                    minDiff = min(minDiff, abs(totalSum - 2 * (a + b)));
                }
                if (it != rVec.begin()) {
                    int b = *prev(it);
                    minDiff = min(minDiff, abs(totalSum - 2 * (a + b)));
                }
            }
        }

        return minDiff;
    }
};