class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int i = 0;
        unordered_map<string,int> mp1;
        unordered_map<char,int> mp2;
        stringstream ss(s);
        string word;
        while(ss >> word){
            if(i == n || mp1[word] != mp2[pattern[i]]){
                return false;
            }
            mp2[pattern[i]] = i + 1;
            mp1[word] = i + 1;
            i++;
        }
        return i == n;
    }
};