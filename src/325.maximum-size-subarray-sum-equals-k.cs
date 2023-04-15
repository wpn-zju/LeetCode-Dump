public class Solution {
    public int MaxSubArrayLen(int[] nums, int k)
    {
        int m = nums.Length;
        if (m == 0)
            return 0;
        int sum = 0;
        int maxLength = 0;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        dic[0] = -1;
        for(int i = 0;i<m;++i)
        {
            sum += nums[i];
            if (!dic.ContainsKey(sum))
                dic[sum] = i;
            if (dic.ContainsKey(sum - k))
                if (i - dic[sum - k] > maxLength)
                    maxLength = i - dic[sum - k];
        }
        return maxLength;
    }
}