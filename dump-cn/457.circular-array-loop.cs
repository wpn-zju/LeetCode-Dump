public class Solution {
    public bool CircularArrayLoop(int[] nums)
    {
        int m = nums.Length;
        for (int i = 0; i < m; ++i)
        {
            int ptr1 = i;
            int ptr2 = i;
            int count = 0;
            int first = nums[ptr1];
            do
            {
                if (first * nums[ptr1] < 0)
                {
                    count = 0;
                    break;
                }
                ptr1 = ((ptr1 + nums[ptr1]) % m + m) % m;
                if (first * nums[ptr2] < 0)
                {
                    count = 0;
                    break;
                }
                ptr2 = ((ptr2 + nums[ptr2]) % m + m) % m;
                if (first * nums[ptr2] < 0)
                {
                    count = 0;
                    break;
                }
                ptr2 = ((ptr2 + nums[ptr2]) % m + m) % m;
                count++;
            } while (ptr1 != ptr2);
            if (count > 1 && ((ptr1 + nums[ptr1]) % m + m) % m != ptr1)
                return true;
        }
        return false;
    }
}