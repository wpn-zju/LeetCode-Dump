public class Solution {
    public int MaxUncrossedLines(int[] A, int[] B)
    {
        int m = A.Length;
        int n = B.Length;
        int[,] dp = new int[m + 1, n + 1];
        for (int i = 0; i <= m; ++i)
            dp[i, 0] = 0;
        for (int i = 0; i <= n; ++i)
            dp[0, i] = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i, j] = A[i - 1] == B[j - 1] ? dp[i - 1, j - 1] + 1 : Math.Max(dp[i - 1, j], dp[i, j - 1]);
        return dp[m, n];
    }
}