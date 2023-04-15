public class Solution {
    public int Combine2Char(char a, char b)
    {
        return (a - '0') * 10 + (b - '0');
    }

    public int NumDecodings(string s)
    {
        int m = s.Length;
        if (m == 0)
            return m;
        if (m == 1)
            return s[0] == '0' ? 0 : 1;
        int[] dp = new int[m];
        dp[0] = s[0] == '0' ? 0 : 1;
        {
            int tmp = Combine2Char(s[0], s[1]);
            if (tmp >= 10 && tmp <= 26)
            {
                if (s[1] == '0')
                    dp[1] = 1;
                else
                    dp[1] = 2;
            }
            else
            {
                if (s[1] == '0')
                    dp[1] = 0;
                else
                    dp[1] = dp[0];
            }

        }
        for(int i = 2; i < m; ++i)
        {
            int tmp = Combine2Char(s[i - 1], s[i]);
            if (tmp >= 10 && tmp <= 26)
                if (s[i] == '0')
                    dp[i] = dp[i - 2];
                else
                    dp[i] = dp[i - 1] + dp[i - 2];
            else
                if (s[i] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
        }
        return dp[m - 1];
    }
}