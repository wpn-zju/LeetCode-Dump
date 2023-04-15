public class Solution {
    public string ReverseWords(string s)
    {
        string result = "";
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < s.Length)
        {
            while (ptr2 < s.Length && s[ptr2] != ' ')
                ptr2++;
            char[] subStr = s.Substring(ptr1, ptr2 - ptr1).ToArray();
            Array.Reverse(subStr);
            result += new string(subStr);
            result += ' ';
            ptr2++;
            ptr1=ptr2;
        }
        return result.Substring(0,s.Length);
    }
}