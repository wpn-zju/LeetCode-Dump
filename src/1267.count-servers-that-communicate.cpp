class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(), 0);
        for(int i = 0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                rows[i] += grid[i][j];
            }
        }
        for(int i = 0;i<grid[0].size();++i){
            for(int j =0;j<grid.size();++j){
                cols[i] += grid[j][i];
            }
        }
        int result = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                result += grid[i][j] && (rows[i] > 1 || cols[j] > 1);
            }
        }
        return result;
    }
};