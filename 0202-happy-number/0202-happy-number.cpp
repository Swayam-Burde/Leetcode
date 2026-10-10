class Solution {
public:
    int sum(int n){
        int val = 0;
        while(n > 0){
            int temp = n % 10;
            val += temp * temp;
            n /= 10;
        }
        return val;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1 && !st.count(n)){
            st.insert(n);
            n = sum(n);
        }
        return n == 1;
    }
};