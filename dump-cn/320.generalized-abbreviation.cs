public class Solution {
    public int GetByte(int num, int offset)
    {
        return (num & 1 << offset) >> offset;
    }

    public IList<string> GenerateAbbreviations(string word)
    {
        List<string> result = new List<string>();
        int l = word.Length;
        int num = (int)Math.Pow(2, l);
        for(int i = 0; i < num; ++i)
        {
            string res = "";
            for (int j = l - 1; j >= 0; --j)
            {
                int tmp = GetByte(i, j);
                if (tmp == 1)
                    res += tmp.ToString();
                else
                    res += word[l - j - 1];
            }
            int count = 0;
            string resout = "";
            for(int j = 0; j < res.Length; ++j)
            {
                if (res[j] == '1')
                    count++;
                else
                {
                    if (count != 0)
                    {
                        resout += count.ToString();
                        count = 0;
                    }
                    resout += res[j];
                }
            }
            if (count != 0)
                resout += count.ToString();
            result.Add(resout);
        }
        return result;
    }
}