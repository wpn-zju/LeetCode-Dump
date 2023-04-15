public class Solution {
    public int[][] GenerateMatrix(int n)
    {
        int[][] result = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            result[i] = new int[n];
            for (int j = 0; j < n; ++j)
                result[i][j] = 0;
        }
        int count = 1;
        int direction = 0;
        int x = 0, y = 0;
        result[0][0] = 1;
        while (true)
        {
            switch (direction)
            {
                case 0:
                    if (y + 1 != n && result[x][y + 1] == 0)
                    {
                        y++;
                        count++;
                        result[x][y] = count;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 1:
                    if (x + 1 != n && result[x + 1][y] == 0)
                    {
                        x++;
                        count++;
                        result[x][y] = count;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 2:
                    if (y - 1 != -1 && result[x][y - 1] == 0)
                    {
                        y--;
                        count++;
                        result[x][y] = count;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 3:
                    if (x - 1 != -1 && result[x - 1][y] == 0)
                    {
                        x--;
                        count++;
                        result[x][y] = count;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
            }
            if (count == n * n)
                break;
        }
        return result;
    }
}