public class Solution {
    public int MinDistance(string word1, string word2)
    {
        int[][] minDis = new int[word1.Length+1][];
        for (int i = 0; i <= word1.Length; ++i)
            minDis[i] = new int[word2.Length+1];
        for (int i = 0; i <= word1.Length; ++i)
            minDis[i][0] = i;
        for (int i = 0; i <= word2.Length; ++i)
            minDis[0][i] = i;
        for(int i = 1; i <= word1.Length; ++i)
        {
            for(int j = 1; j <= word2.Length; ++j)
            {
                if (word1[i-1] == word2[j-1])
                {
                    minDis[i][j] = 1 + Math.Min(Math.Min(minDis[i - 1][j], minDis[i][j - 1]), minDis[i - 1][j - 1] - 1);
                }
                else
                {
                    minDis[i][j] = 1 + Math.Min(Math.Min(minDis[i - 1][j], minDis[i][j - 1]), minDis[i - 1][j - 1]);
                }
            }
        }
        return minDis[word1.Length][word2.Length];
    }
}