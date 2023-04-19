class Solution {
    public void sortColors(int[] nums) {
        if (nums.length < 2)
            return;
        int head = 0;
        int tail = nums.length - 1;
        int ptr = 0;
        while (ptr != tail + 1)
        {
            int tmp;
            switch (nums[ptr])
            {
                case 0:
                    tmp = nums[head];
                    nums[head] = nums[ptr];
                    nums[ptr] = tmp;
                    head++;
                    if (ptr < head)
                        ptr = head;
                    break;
                case 1:
                    ptr++;
                    break;
                case 2:
                    tmp = nums[tail];
                    nums[tail] = nums[ptr];
                    nums[ptr] = tmp;
                    tail--;
                    break;
            }
        }
    }
}