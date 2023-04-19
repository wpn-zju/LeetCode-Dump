public class Solution {
    public void ReverseString(char[] s)
    {
        int m = s.Length;
        if (m < 2)
            return;
        int ptr = 0;
        while (ptr < m - 1 - ptr)
        {
            char tmp = s[ptr];
            s[ptr] = s[m - 1 - ptr];
            s[m - 1 - ptr] = tmp;
            ptr++;
        }
    }
}