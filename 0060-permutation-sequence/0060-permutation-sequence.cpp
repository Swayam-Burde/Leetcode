class Solution {
public:
    string getPermutation(int n, int k) {
        string num = "";
        string target = "";
        for (int i = 1; i <= n; i++) {
            num = num + to_string(i);
        }

        for (int i = 0; i < k - 1; i++) {
            next_permutation(num.begin(), num.end());
        }
        return num;
    }
};