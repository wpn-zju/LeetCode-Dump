public class Solution {
    public int MinSubArrayLen(int s, int[] nums)
    {
        int m = nums.Length;
        if (m == 0)
            return 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int sum = 0;
        int minLength = int.MaxValue;
        while (ptr2 != m)
        {
            sum += nums[ptr2];
            if(sum>=s){
                while (sum >= s)
                    sum -= nums[ptr1++];
                if (ptr2 - ptr1 + 2 < minLength)
                    minLength = ptr2 - ptr1 + 2;
            }
            ptr2++;
        }
        return minLength == int.MaxValue ? 0 : minLength;
    }
}