class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || (long long)num * 9 < sum) {
            return "";
        }
        int count9 = sum / 9;
        int rem = sum % 9;
        string result = "";
        result.reserve(num);
        result.append(count9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        int remainingZeros = num - result.size();
        if (remainingZeros > 0) {
            result.append(remainingZeros, '0');
        }
        return result;
    }
};