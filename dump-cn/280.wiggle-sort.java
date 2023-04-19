class Solution {
    public void wiggleSort(int[] nums) {
        if (nums.length < 2)
            return;
        int ptr = 0;
        int m = nums.length;
        while (ptr != m - 1)
        {
            if (ptr % 2 == 0)
            {
                if (nums[ptr] > nums[ptr + 1])
                {
                    int tmp = nums[ptr + 1];
                    nums[ptr + 1] = nums[ptr];
                    nums[ptr] = tmp;
                }
            }
            else
            {
                if (nums[ptr] < nums[ptr + 1])
                {
                    int tmp = nums[ptr + 1];
                    nums[ptr + 1] = nums[ptr];
                    nums[ptr] = tmp;
                }
            }
            ptr++;
        }
    }
}