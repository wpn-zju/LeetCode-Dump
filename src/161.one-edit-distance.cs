public class Solution {
    public bool IsOneEditDistance(string s, string t)
    {
        int sL = s.Length;
        int tL = t.Length;
        if (s == t || Math.Abs(sL - tL) > 1)
            return false;
        if(sL==0||tL==0)
            return sL+tL==1;
        if (sL == tL)
        {
            int count = 0;
            for (int i = 0; i < s.Length; ++i)
                if (s[i] != t[i])
                    count++;
            return count == 1;
        }
        else if(sL<tL)
        {
            int i = 0, j = 0;
            int count = 0;
            while (j != tL && i != sL)
            {
                if (s[i] != t[j])
                {
                    j++;
                    count++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            return i==j?count==0:count == 1;
        }
        else
        {
            int i = 0, j = 0;
            int count = 0;
            while (j != tL && i != sL)
            {
                if (s[i] != t[j])
                {
                    i++;
                    count++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            return i==j?count==0:count == 1;
        }
    }
}