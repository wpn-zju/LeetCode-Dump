class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1)
            return 0;
        int m = nums.length;
        int result = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int product = 1;
        while (ptr2 != m)
        {
            product *= nums[ptr2];
            while (product >= k)
                product /= nums[ptr1++];
            result += ptr2 - ptr1 + 1;
            ptr2++;
        }
        return result;
    }
}