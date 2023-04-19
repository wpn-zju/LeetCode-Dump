public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k)
    {
        if (k <= 1)
            return 0;
        int m = nums.Length;
        int result = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int product = 1;
        while (ptr2 != m)
        {
            product *= nums[ptr2++];
            while (product >= k)
                product /= nums[ptr1++];
            result += ptr2 - ptr1;  // Key Step Here
        }
        return result;
    }
}