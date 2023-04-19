public class Solution {
    public int[] SortedSquares(int[] A)
    {
        if (A.Length == 0)
            return A;
        int[] result = new int[A.Length];
        int m = A.Length;
        int ptr = 0;
        int minAbs = int.MaxValue;
        int minAbsPtr = ptr;
        while (ptr < m)
        {
            if(Math.Abs(A[ptr]) < minAbs)
            {
                minAbs = Math.Abs(A[ptr]);
                minAbsPtr = ptr;
            }
            ptr++;
        }
        result[0] = minAbs * minAbs;
        int ptrl = minAbsPtr - 1;
        int ptrr = minAbsPtr + 1;
        ptr = 1;
        while (ptrl != -1 || ptrr != m)
        {
            if (ptrl != -1 && ptrr != m)
            {
                int sq1 = A[ptrl] * A[ptrl];
                int sq2 = A[ptrr] * A[ptrr];
                if (sq1 < sq2)
                {
                    result[ptr] = sq1;
                    ptrl--;
                }
                else
                {
                    result[ptr] = sq2;
                    ptrr++;
                }
                ptr++;
            }
            else if (ptrr != m)
            {
                result[ptr] = A[ptrr] * A[ptrr];
                ptrr++;
                ptr++;
            }
            else
            {
                result[ptr] = A[ptrl] * A[ptrl];
                ptrl--;
                ptr++;
            }
        }
        return result;
    }
}