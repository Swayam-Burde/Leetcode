class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int sum = accumulate(piles.begin(),piles.end(), 0);
        long long aSum =0, bSum = 0;
        for(int i = n-1; i >= 0; i -= 2){
            aSum += piles[i];
        }
        bSum = sum - aSum;
        return aSum > bSum;
    }
};