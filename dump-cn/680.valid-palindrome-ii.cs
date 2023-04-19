public class Solution {
    public bool ValidPalindrome(string s)
    {
        int m = s.Length;
        int ptr1 = 0;
        int ptr2 = m - 1;
        while (ptr1 < ptr2)
        {
            if (s[ptr1] != s[ptr2])
                return IsMyPalindrome(s.Substring(ptr1 + 1, ptr2 - ptr1)) || IsMyPalindrome(s.Substring(ptr1, ptr2 - ptr1));
            ptr1++;
            ptr2--;
        }
        return true;
    }

    public bool IsMyPalindrome(string s)
    {
        int m = s.Length;
        int ptr1 = 0, ptr2 = m - 1;
        while (ptr1 < ptr2)
        {
            if (s[ptr1] != s[ptr2])
                return false;
            ptr1++;
            ptr2--;
        }
        return true;
    }
}