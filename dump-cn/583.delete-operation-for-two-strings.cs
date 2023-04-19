public class Solution {
    public int MinDistance(string word1, string word2)
    {
        int[,] dp = new int[word1.Length+1, word2.Length+1];
        for (int i = 0; i <= word1.Length; ++i)
            dp[i, 0] = i;
        for (int i = 0; i <= word2.Length; ++i)
            dp[0, i] = i;
        for(int i = 1; i <= word1.Length; ++i)
            for(int j = 1; j <= word2.Length; ++j)
                dp[i, j] = word1[i - 1] == word2[j - 1] ? dp[i - 1, j - 1] : (Math.Min(dp[i - 1, j], dp[i, j - 1]) + 1);
        return dp[word1.Length, word2.Length];
    }
}