public class Solution {
    public int LongestValidParentheses(string s)
    {
        int m = s.Length;
        if (m < 2) return 0;
        int[] dp = new int[m];
        Stack<int> lastL = new Stack<int>();
        Stack<int> lastR = new Stack<int>();
        // Init
        dp[0] = 0;
        switch (s.Substring(0,2))
        {
            case "((":
                {
                    dp[1] = 0;
                    lastL.Push(0);
                    lastL.Push(1);
                }
                break;
            case "()":
                {
                    dp[1] = 2;
                }
                break;
            case ")(":
                {
                    dp[1] = 0;
                    lastL.Push(1);
                    lastR.Push(0);
                }
                break;
            case "))":
                {
                    dp[1] = 0;
                    lastR.Push(0);
                    lastR.Push(1);
                }
                break;
        }
        // Loop
        for (int i = 2; i < m; ++i)
        {
            if (s[i] == '(')
            {
                dp[i] = dp[i - 1];
                lastL.Push(i);
            }
            else
            {
                // 最后一个未配对的右括号必定在最后一个未配对的左括号前面
                // Case 1 左栈没了
                if (lastL.Count == 0)
                {
                    dp[i] = dp[i - 1];
                    lastR.Push(i);
                }
                // Case 2 右栈没了
                else if (lastR.Count == 0)
                {
                    lastL.Pop();
                    if (lastL.Count == 0)
                        dp[i] = i + 1;
                    else
                        dp[i] = Math.Max(dp[i - 1], i - lastL.Peek());
                }
                // Case 3 左右栈都有 右栈最末比在左栈最末之前
                else
                {
                    lastL.Pop();
                    if (lastL.Count == 0)
                        dp[i] = Math.Max(dp[i - 1], i - lastR.Peek());
                    else
                        dp[i] = Math.Max(dp[i - 1], i - lastL.Peek());
                }
            }
        }
        return dp[m - 1];
    }
}