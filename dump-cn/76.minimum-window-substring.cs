public class Solution {
    public string MinWindow(string s, string t)
    {
        int m = s.Length;
        int n = t.Length;
        if (m == 0 || n == 0)
            return "";
        int ptrL = 0;
        int ptrR = 0;
        int count = 0;
        Dictionary<char, int> charDic = new Dictionary<char, int>();
        Dictionary<char, int> curDic = new Dictionary<char, int>();
        foreach (char c in t)
            if (charDic.ContainsKey(c))
                charDic[c]++;
            else
                charDic[c] = 1;
        int countNeed = charDic.Count;
        int[] result = new int[3] { -1, 0, 0 };
        while (ptrR != m)
        {
            char c = s[ptrR];
            if (curDic.ContainsKey(c))
                curDic[c]++;
            else
                curDic[c] = 1;

            if (charDic.ContainsKey(c) && curDic[c] == charDic[c])
                count++;

            while(ptrL<=ptrR && count == countNeed)
            {
                c = s[ptrL];
                if(result[0] == -1||ptrR-ptrL+1<result[0])
                {
                    result[0] = ptrR - ptrL + 1;
                    result[1] = ptrL;
                    result[2] = ptrR;
                }

                curDic[c]--;
                if (charDic.ContainsKey(c) && curDic[c] < charDic[c])
                    count--;

                ptrL++;
            }
            ptrR++;
        }

        return result[0] == -1 ? "" : s.Substring(result[1], result[0]);
    }
}