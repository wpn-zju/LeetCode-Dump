public class Solution {
    public bool IsPalindrome(string s)
    {
        s = s.ToLower();
        int m = s.Length;
        int ptr1 = 0;
        int ptr2 = m - 1;
        while (ptr1 < ptr2)
        {
            int i1 = s[ptr1] - 'a';
            int i2 = s[ptr1] - '0';
            int i3 = s[ptr2] - 'a';
            int i4 = s[ptr2] - '0';
            if ((i1 < 0 || i1 > 25) && (i2 < 0 || i2 > 9))
                ptr1++;
            else if ((i3 < 0 || i3 > 25) && (i4 < 0 || i4 > 9))
                ptr2--;
            else if (s[ptr1] != s[ptr2])
                return false;
            else
            {
                ptr1++;
                ptr2--;
            }
        }
        return true;
    }
}