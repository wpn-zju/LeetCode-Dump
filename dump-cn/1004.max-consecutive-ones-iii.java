class Solution {
    public int longestOnes(int[] A, int K) {
        int max = 0;        // 最大值
        int cur = 0;        // 当前值
        int ptr = 0;        // 前进指针
        int breakPtr = -1;  // 置1断点
        int breakCount = 0;
        while (ptr != A.length)
        {
            if (A[ptr] == 1)
                cur++;
            else if (K != 0)
            {
                if (breakCount == 0)
                {
                    breakPtr = ptr;
                    breakCount++;
                    cur++;
                }
                else if(breakCount < K)
                {
                    breakCount++;
                    cur++;
                }
                else
                {
                    cur = ptr - breakPtr;
                    while (A[++breakPtr] == 1) ;
                }
            }
            else
                cur = 0;
            if (cur > max)
                max = cur;
            ptr++;
        }
        return max;
    }
}