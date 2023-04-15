class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for(int i =0;i<grid.size();++i){
            for(int j =0 ;j<grid[0].size();++j){
                if(grid[i][j])
                    area += 2;
                if(i == 0 || grid[i - 1][j] < grid[i][j]){
                    area += grid[i][j];
                    if(i != 0)
                        area -= grid[i - 1][j];
                }
                if(i == grid.size() - 1 || grid[i + 1][j] < grid[i][j]){
                    area += grid[i][j];
                    if(i != grid.size() - 1)
                        area -= grid[i + 1][j];
                }
                if(j == 0 || grid[i][j - 1] < grid[i][j]){
                    area += grid[i][j];
                    if(j != 0)
                        area -= grid[i][j - 1];
                }
                if(j == grid[0].size() - 1 || grid[i][j + 1] < grid[i][j]){
                    area += grid[i][j];
                    if(j != grid[0].size() - 1)
                        area -= grid[i][j + 1];
                }            
            }
        }
        return area;
    }
};