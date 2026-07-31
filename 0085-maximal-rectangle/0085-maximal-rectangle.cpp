class Solution {
public:
    int largest(vector<int>& height){
        stack<int> st;
        int maxA = 0;
        int n = height.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || height[st.top()] >= height[i])){
                int ht = height[st.top()];
                st.pop();
                int wt;
                if(st.empty()) wt = i;
                else{
                    wt = i - st.top() - 1;
                }
                maxA = max(maxA, wt*ht);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largest(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};