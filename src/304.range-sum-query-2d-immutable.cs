    public class NumMatrix
    {
        public int[][] sumArray;
        public NumMatrix(int[][] matrix)
        {
            if(matrix.Length == 0 || matrix[0].Length == 0)
                return;
            sumArray = new int[matrix.Length][];
            for (int i = 0; i < matrix.Length; ++i)
                sumArray[i] = new int[matrix[0].Length];
            int sum = 0;
            for(int i = 0;i<matrix.Length;++i)
                sumArray[i][0] = sum += matrix[i][0];
            sum = 0;
            for(int i = 0;i<matrix[0].Length;++i)
                sumArray[0][i] = sum += matrix[0][i];
            for (int i = 1; i < matrix.Length; ++i)
                for (int j = 1; j < matrix[0].Length; ++j)
                    sumArray[i][j] = sumArray[i - 1][j] + sumArray[i][j - 1] - sumArray[i - 1][j - 1] + matrix[i][j];
        }

        public int SumRegion(int row1, int col1, int row2, int col2)
        {
            if (row1 == 0 && col1 == 0)
                return sumArray[row2][col2];
            else if (row1 == 0)
                return sumArray[row2][col2] - sumArray[row2][col1 - 1];
            else if (col1 == 0)
                return sumArray[row2][col2] - sumArray[row1 - 1][col2];
            else
                return sumArray[row2][col2] + sumArray[row1 - 1][col1 - 1] - sumArray[row1 - 1][col2] - sumArray[row2][col1 - 1];
        }
    }