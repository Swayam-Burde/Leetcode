class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n > 0){
            arr.push_back(n % 10);
            n /= 10;
        }
        sort(arr.begin(),arr.end());
        int len = arr.size();
        return arr[len-1]*arr[len-2];
    }
};