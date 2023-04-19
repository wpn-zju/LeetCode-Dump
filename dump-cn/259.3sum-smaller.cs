public class Solution {
    public int ThreeSumSmaller(int[] nums, int target)
    {
        int m = nums.Length;
        List<int> list = nums.ToList();
        list.Sort();
        int result = 0;
        for (int ptr1 = 0; ptr1 < m - 2; ++ptr1)
        {
            int ptr2 = ptr1 + 1;
            int ptr3 = m - 1;
            int targetN = target - list[ptr1];
            int sum = 0;
            while (ptr2 < ptr3)
            {
                sum = list[ptr2] + list[ptr3];
                if (sum < targetN)
                {
                    result += ptr3 - ptr2;
                    ptr2++;
                }
                else
                    ptr3--;
            }
        }
        return result;
    }
}