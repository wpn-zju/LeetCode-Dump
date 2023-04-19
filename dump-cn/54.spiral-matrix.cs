public class Solution {
    public IList<int> SpiralOrder(int[][] matrix)
    {
        List<int> result = new List<int>();
        if (matrix.Length == 0)
            return result;
        bool[][] bools = new bool[matrix.Length][];
        for (int i = 0; i < matrix.Length; ++i)
            bools[i] = new bool[matrix[0].Length];
        for (int i = 0; i < matrix.Length; ++i)
            for (int j = 0; j < matrix[0].Length; ++j)
                bools[i][j] = true;
        int height = matrix.Length;
        int width = matrix[0].Length;
        int direction = 0; // ESWN = 0123
        int x = 0, y = 0;
        result.Add(matrix[0][0]);
        bools[0][0] = false;
        while (true)
        {
            switch (direction)
            {
                case 0:
                    if (y + 1 != width && bools[x][y + 1])
                    {
                        y++;
                        result.Add(matrix[x][y]);
                        bools[x][y] = false;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 1:
                    if (x + 1 != height && bools[x + 1][y])
                    {
                        x++;
                        result.Add(matrix[x][y]);
                        bools[x][y] = false;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 2:
                    if (y - 1 != -1 && bools[x][y - 1])
                    {
                        y--;
                        result.Add(matrix[x][y]);
                        bools[x][y] = false;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
                case 3:
                    if (x - 1 != -1 && bools[x - 1][y])
                    {
                        x--;
                        result.Add(matrix[x][y]);
                        bools[x][y] = false;
                    }
                    else
                    {
                        direction += 1;
                        direction %= 4;
                    }
                    break;
            }
            if (result.Count == height * width)
                break;
        }
        return result;
    }
}