public class Solution {
    public int TotalHammingDistance(int[] nums)
    {
        int result = 0;
        for(int i = 0; i < 32; ++i)
        {
            int count0 = 0;
            int count1 = 0;
            foreach(int n in nums)
                if ((n & 1 << i) >> i == 0)
                    count0++;
                else
                    count1++;
            result += count0 * count1;
        }
        return result;
    }
}