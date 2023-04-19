public class Solution {
    public int TotalFruit(int[] tree)
    {
        int m = tree.Length;
        if (m < 3)
            return m;
        Dictionary<int, int> dic = new Dictionary<int, int>();  // 记录最后一个出现字符c的位置
        int ptr = 0;
        while (ptr != m - 1 && tree[ptr + 1] == tree[ptr])
            ptr++;
        if (ptr == m - 1)
            return m;
        ptr++;
        int basket1 = tree[0];
        int basket2 = tree[ptr];
        int max = ptr + 1;
        int cur = ptr + 1;
        dic[tree[0]] = ptr - 1;
        dic[tree[ptr]] = ptr;
        ptr++;
        while (ptr != m)
        {
            dic[tree[ptr]] = ptr;
            if (tree[ptr] == basket1 || tree[ptr] == basket2)
            {
                if (++cur > max)
                    max = cur;
            }
            else
            {
                if (tree[ptr - 1] == basket1)
                {
                    cur = ptr - dic[basket2];
                    basket2 = tree[ptr];
                }
                else
                {
                    cur = ptr - dic[basket1];
                    basket1 = tree[ptr];
                }
            }
            ptr++;
        }
        return max;
    }
}