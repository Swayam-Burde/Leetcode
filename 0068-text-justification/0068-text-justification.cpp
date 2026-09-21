class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int left = 0, right = 0;
        while( left < n){
            int len = 0;
            while(right < n && len + words[right].size() + (right - left) <= maxWidth){
                len += words[right].size();
                right++;
            }
            int num = right - left;
            int spaces = maxWidth - len;
            string temp = "";
            if(right == n || num == 1){
                for(int i = left; i < right; i++){
                    temp += words[i];
                    if(i < right - 1){
                        temp += " ";
                    }
                }
                temp.append(maxWidth- temp.size(), ' ');
            }
            else{
                int space_allign = spaces / (num - 1);
                int extra = spaces % (num - 1);
                for(int i = left; i < right; i++){
                    temp += words[i];
                    if( i < right - 1){
                        int curr = space_allign + (i - left < extra ? 1 : 0); 
                        temp.append(curr, ' ');
                    }
                }
            }
            ans.push_back(temp);
            left = right;
        }
        return ans;
    }
};