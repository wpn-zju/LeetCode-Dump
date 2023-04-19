public class Solution {
    public int MinimumDeleteSum(string s1, string s2)
    {
        // 只需要前一行 dp 数组的值，所以我们可以使用一个一维 dp 数组
        int[,] dp = new int[s1.Length + 1, s2.Length + 1];
        int tmp = 0;
        dp[0, 0] = 0;
        for (int i = 1; i <= s1.Length; ++i)
        {
            tmp += s1[i - 1];
            dp[i, 0] = tmp;
        }
        tmp = 0;
        for (int i = 1; i <= s2.Length; ++i)
        {
            tmp += s2[i - 1];
            dp[0, i] = tmp;
        }
        for (int i = 1; i <= s1.Length; ++i)
            for (int j = 1; j <= s2.Length; ++j)
                dp[i, j] = s1[i - 1] == s2[j - 1] ? dp[i - 1, j - 1] : (Math.Min(dp[i - 1, j] + s1[i - 1], dp[i, j - 1] + s2[j - 1]));
        return dp[s1.Length, s2.Length];
    }
}