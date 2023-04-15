public class Solution {
    // 自底向上和自顶向下的区别 本题只能用自底向上
    public int CalculateMinimumHP(int[][] dungeon)
    {
        int m = dungeon.Length;
        int n = dungeon[0].Length;
        int[,] dp = new int[m, n];
        int temp = 0;
        for(int i = m - 1; i >= 0; --i)
        {
            temp += dungeon[i][n-1];
            if (temp > 0)
                temp = 0;
            dp[i, n-1] = temp;
        }
        temp = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            temp += dungeon[m-1][i];
            if (temp > 0)
                temp = 0;
            dp[m-1, i] = temp;
        }
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                int tmp = Math.Max(dp[i + 1, j], dp[i, j + 1]);
                dp[i, j] = dungeon[i][j] + tmp < 0 ? dungeon[i][j] + tmp : 0;
            }
        }
        return -dp[0, 0] + 1;
    }
}