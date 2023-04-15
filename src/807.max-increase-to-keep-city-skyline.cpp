class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(), 0);
        for(int i = 0;i<grid.size();++i){
            int mx = 0;
            for(int j =0;j<grid[0].size();++j){
                mx = max(grid[i][j], mx);
            }
            rows[i] = mx;
        }
        for(int i = 0;i<grid[0].size();++i){
            int mx = 0;
            for(int j =0;j<grid.size();++j){
                mx = max(grid[j][i], mx);
            }
            cols[i] = mx;
        }
        int result = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                result += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        return result;
    }
};