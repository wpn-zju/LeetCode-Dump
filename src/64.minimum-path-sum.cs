public class Solution {
    public int MinPathSum(int[][] grid)
    {
        int[,] dp = new int[grid.Length, grid[0].Length];
        int tmp = 0;
        for(int i = 0; i < grid.Length; ++i)
        {
            tmp += grid[i][0];
            dp[i, 0] = tmp;
        }
        tmp = 0;
        for(int i = 0; i < grid[0].Length; ++i)
        {
            tmp += grid[0][i];
            dp[0, i] = tmp;
        }
        for (int i = 1; i < grid.Length; ++i)
            for (int j = 1; j < grid[0].Length; ++j)
                dp[i, j] = grid[i][j] + Math.Min(dp[i - 1, j], dp[i, j - 1]);
        return dp[grid.Length - 1, grid[0].Length - 1];
    }
}