public class Solution {
    public int TwoSumLessThanK(int[] A, int K)
    {
        int m = A.Length;
        List<int> list = A.ToList();
        list.Sort();
        int result = -1;
        int minDiff = int.MaxValue;
        int ptr1 = 0;
        int ptr2 = m - 1;
        while (ptr1 < ptr2)
        {
            int sum = list[ptr1] + list[ptr2];
            if (sum < K && K - sum < minDiff)
            {
                result = sum;
                minDiff = K - sum;
            }
            if (sum >= K)
                ptr2--;
            else
                ptr1++;
        }
        return result;
    }
}