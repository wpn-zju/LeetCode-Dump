public class Solution {
    public int LengthOfLongestSubstringTwoDistinct(string s)
    {
        int m = s.Length;
        if (m < 3)
            return m;
        Dictionary<int, int> dic = new Dictionary<int, int>();  // 记录最后一个出现字符c的位置
        int ptr = 0;
        while (ptr != m - 1 && s[ptr + 1] == s[ptr])
            ptr++;
        if (ptr == m - 1)
            return m;
        ptr++;
        int basket1 = s[0];
        int basket2 = s[ptr];
        int max = ptr + 1;
        int cur = ptr + 1;
        dic[s[0]] = ptr - 1;
        dic[s[ptr]] = ptr;
        ptr++;
        while (ptr != m)
        {
            dic[s[ptr]] = ptr;
            if (s[ptr] == basket1 || s[ptr] == basket2)
            {
                if (++cur > max)
                    max = cur;
            }
            else
            {
                if (s[ptr - 1] == basket1)
                {
                    cur = ptr - dic[basket2];
                    basket2 = s[ptr];
                }
                else
                {
                    cur = ptr - dic[basket1];
                    basket1 = s[ptr];
                }
            }
            ptr++;
        }
        return max;
    }
}