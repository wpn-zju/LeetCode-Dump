public class Solution {
    public int[] SortTransformedArray(int[] nums, int a, int b, int c)
    {
        if (nums.Length == 0)
            return nums;
        double quan = (double)b / a / -2;
        int[] result = new int[nums.Length];
        int m = nums.Length;
        int ptr = 0;
        double minAbs = int.MaxValue;
        int minAbsPtr = ptr;
        while (ptr < m)
        {
            if (Math.Abs(nums[ptr] - quan) < minAbs)
            {
                minAbs = Math.Abs(nums[ptr] - quan);
                minAbsPtr = ptr;
            }
            ptr++;
        }
        if (a > 0)
        {
            result[0] = a * nums[minAbsPtr] * nums[minAbsPtr] + b * nums[minAbsPtr] + c;
            int ptrl = minAbsPtr - 1;
            int ptrr = minAbsPtr + 1;
            ptr = 1;
            while (ptrl != -1 || ptrr != m)
            {
                if (ptrl != -1 && ptrr != m)
                {
                    int i1 = a * nums[ptrl] * nums[ptrl] + b * nums[ptrl] + c;
                    int i2 = a * nums[ptrr] * nums[ptrr] + b * nums[ptrr] + c;
                    if (i1 < i2)
                    {
                        result[ptr] = i1;
                        ptrl--;
                    }
                    else
                    {
                        result[ptr] = i2;
                        ptrr++;
                    }
                    ptr++;
                }
                else if (ptrr != m)
                {
                    result[ptr] = a * nums[ptrr] * nums[ptrr] + b * nums[ptrr] + c;
                    ptrr++;
                    ptr++;
                }
                else
                {
                    result[ptr] = a * nums[ptrl] * nums[ptrl] + b * nums[ptrl] + c;
                    ptrl--;
                    ptr++;
                }
            }
        }
        else if (a < 0)
        {
            result[m - 1] = a * nums[minAbsPtr] * nums[minAbsPtr] + b * nums[minAbsPtr] + c;
            int ptrl = minAbsPtr - 1;
            int ptrr = minAbsPtr + 1;
            ptr = m - 2;
            while (ptrl != -1 || ptrr != m)
            {
                if (ptrl != -1 && ptrr != m)
                {
                    int i1 = a * nums[ptrl] * nums[ptrl] + b * nums[ptrl] + c;
                    int i2 = a * nums[ptrr] * nums[ptrr] + b * nums[ptrr] + c;
                    if (i1 < i2)
                    {
                        result[ptr] = i2;
                        ptrr++;
                    }
                    else
                    {
                        result[ptr] = i1;
                        ptrl--;
                    }
                    ptr--;
                }
                else if (ptrr != m)
                {
                    result[ptr] = a * nums[ptrr] * nums[ptrr] + b * nums[ptrr] + c;
                    ptrr++;
                    ptr--;
                }
                else
                {
                    result[ptr] = a * nums[ptrl] * nums[ptrl] + b * nums[ptrl] + c;
                    ptrl--;
                    ptr--;
                }
            }
        }
        else
        {
            if (b > 0)
                for (int i = 0; i < m; ++i)
                    result[i] = b * nums[i] + c;
            else
                for (int i = 0; i < m; ++i)
                    result[m - i - 1] = b * nums[i] + c;
        }

        return result;
    }
}