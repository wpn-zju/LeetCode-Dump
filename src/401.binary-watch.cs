public class Solution {
    public IList<string> ReadBinaryWatch(int num)
    {
        List<string> res = new List<string>();
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 60; j++)
                if (count1(i) + count1(j) == num)
                    res.Add(i + ":" + (j < 10 ? ("0" + j).ToString() : j.ToString()));
        return res;
    }

    int count1(int n)
    {
        int res = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
}