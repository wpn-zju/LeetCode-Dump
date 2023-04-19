public class Solution {
    public IList<int> FindSubstring(string s, string[] words)
    {
        List<int> result = new List<int>();
        if (s.Length == 0 || words.Length == 0)
            return result;
        Dictionary<string, int> map = new Dictionary<string, int>();
        foreach (string word in words)
            if (map.ContainsKey(word))
                map[word]++;
            else
                map[word] = 1;

        int length = words[0].Length;
        int i = 0;
        while (i != length)
        {
            Dictionary<string, int> dic = new Dictionary<string, int>(map);
            int j = 0;
            int count = 0;
            while (i + j * length <= s.Length - length)
            {
                string subStr = s.Substring(i + j * length, length);
                if(count!=words.Length)
                    count++;
                if (dic.ContainsKey(subStr))
                {
                    dic[subStr]--;
                    if (dic[subStr] == 0)
                        dic.Remove(subStr);
                }
                else
                    dic[subStr] = -1;
                if(dic.Count == 0)
                    result.Add(i + j * length - words.Length * length + length);
                if (count == words.Length)
                {
                    string del = s.Substring(i + j * length - words.Length * length + length, length);
                    if(dic.ContainsKey(del))
                    {
                        dic[del]++;
                        if(dic[del]==0)
                            dic.Remove(del);
                    }
                    else
                        dic[del] = 1;
                }
                j++;
            }
            i++;
        }
        return result;
    }
}