class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int r = grid.size();
        int c = grid[0].size();
        if( j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        if(i == r - 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = -1e8;
        for(int di = -1; di <= +1; di++){
            for(int dj = -1; dj <= +1; dj++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1, j1 + di, j2 + dj, grid, dp);
                maxi = max(maxi, value); 
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c, vector<int>(c, -1)));
        return f(0, 0, c-1,grid,dp);
    }
};