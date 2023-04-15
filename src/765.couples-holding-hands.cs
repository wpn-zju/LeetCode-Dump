public class Solution {
    public int FindEle(int[] row, int val)
    {
        for(int i = 0;i<row.Length;++i)
            if (row[i] == val)
                return i;
        return -1;
    }

    public int MinSwapsCouples(int[] row)
    {
        int count = 0;

        for (int i = 0; i < row.Length; i += 2)
        {
            int a = row[i];
            int b = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
            if (row[i + 1] == b)
                continue;
            int index = FindEle(row, b);
            int temp = row[i+1];
            row[i + 1] = row[index];
            row[index] = temp;
            count++;
        }

        return count;
    }
}