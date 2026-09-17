class Solution {
public:
    bool isAnagram(string& s, string& t){
        if(s.size() != t.size()){
            return false;
        }
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            freq[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = strs.size();
        vector<bool> valid(n, true);
        for(int i = 0; i < n; i++){
            if(valid[i] == false){
                continue;
            }
            temp.push_back(strs[i]);
            for(int j = i + 1;j < n; j++){
                if(isAnagram(strs[i],strs[j])){
                    temp.push_back(strs[j]);
                    valid[j] = false;
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};