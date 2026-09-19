class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int maxi = 0;
        int cnt = 0;
        int i = 0;
        for(int j = 0; j < s.size(); j++){
            if(isVowel(s[j])){
                cnt++;
            }
            if(j-i+1 == k){
                maxi = max(maxi,cnt);
                if(isVowel(s[i])){
                    cnt--;
                }
                i++;
            }
        }
        return maxi;
    }
};