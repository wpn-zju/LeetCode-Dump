public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s)
    {
        List<string> result = new List<string>();
        Dictionary<uint, int> dic = new Dictionary<uint, int>();
        for(int i = 0; i < s.Length - 9; ++i)
        {
            uint tmp = 0;
            string subStr = s.Substring(i, 10);
            for (int j = 0; j < subStr.Length; ++j)
            {
                switch (subStr[j])
                {
                    // 00
                    case 'A':
                        break;
                    // 01
                    case 'C':
                        tmp |= 1u << j;
                        break;
                    // 10
                    case 'G':
                        tmp |= 1u << 10 + j;
                        break;
                    // 11
                    case 'T':
                        tmp |= (1u << j) + (1u << 10 + j);
                        break;
                }
            }
            if (dic.ContainsKey(tmp))
                dic[tmp]++;
            else
                dic[tmp] = 1;
        }
        foreach(KeyValuePair<uint, int> kvp in dic)
        {
            if (kvp.Value > 1)
            {
                string subStr = "";
                for (int i = 0; i < 10; ++i)
                {
                    uint digit1 = (kvp.Key & (1u << i)) >> i;
                    uint digit2 = (kvp.Key & (1u << 10 + i)) >> 10 + i;
                    if (digit1 == 0 && digit2 == 0)
                        subStr += 'A';
                    else if (digit1 == 1 && digit2 == 0)
                        subStr += 'C';
                    else if (digit1 == 0 && digit2 == 1)
                        subStr += 'G';
                    else if (digit1 == 1 && digit2 == 1)
                        subStr += 'T';
                }
                result.Add(subStr);
            }
        }
        return result;
    }
}