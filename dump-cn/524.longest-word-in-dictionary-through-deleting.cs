public class Solution {
    public string FindLongestWord(string s, IList<string> d)
    {
        string result = "";
        if (s.Length == 0)
            return result;
        foreach (string str in d)
        {
            int ptr1 = 0;
            int ptr2 = 0;
            bool flag = false;
            while (ptr1 != s.Length)
            {
                if (s[ptr1] == str[ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                    ptr1++;
                if (ptr2 == str.Length)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                if (str.Length > result.Length || str.Length == result.Length && str.CompareTo(result) < 0)
                    result = str;
        }
        return result;
    }
}