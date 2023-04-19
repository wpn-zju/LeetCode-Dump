public class Solution {
    public int MaxProduct(string[] words)
    {
        int max = 0;
        uint[] vec = new uint[words.Length];
        for(int i = 0;i<words.Length;++i)
        {
            uint tmp = 0;
            foreach(char c in words[i])
            {
                tmp |= 1u << c - 'a';
            }
            vec[i] = tmp;
        }
        for(int i = 0; i < vec.Length; ++i)
        {
            for(int j = i+1; j < vec.Length; ++j)
            {
                if ((vec[i] & vec[j]) == 0)
                    if (words[i].Length * words[j].Length > max)
                        max = words[i].Length * words[j].Length;
            }
        }
        return max;
    }
}