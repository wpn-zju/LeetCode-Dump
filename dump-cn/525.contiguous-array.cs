public class Solution {
    public int FindMaxLength(int[] nums)
    {
        int m = nums.Length;
        if (m == 0)
            return 0;
        int sum = 0;
        int maxI = 0;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        dic[0] = -1;
        for(int i = 0; i < nums.Length; ++i)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (!dic.ContainsKey(sum))
                dic[sum] = i;
            else if (maxI < i - dic[sum])
                maxI = i - dic[sum];
        }
        return maxI;
    }
}