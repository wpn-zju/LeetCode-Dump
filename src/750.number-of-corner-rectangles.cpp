class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid[0].size(), vector<int>(grid[0].size(), 0));
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                for(int k = j + 1;k <grid[0].size();++k){
                    dp[j][k] += grid[i][j] && grid[i][k];
                }
            }
        }
        int count = 0;
        for(int i = 0;i<dp[0].size();++i){
            for(int j = 0;j<dp[0].size();++j){
                count += dp[i][j] * dp[i][j] - dp[i][j] >> 1;
            }
        }
        return count;
    }
};