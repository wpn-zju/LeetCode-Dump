public class Solution {
    // 方法一  sum       O(n^2) O(1)
    // 方法二  HashMap   O(n)   O(n)
    public int SubarraySum(int[] nums, int k)
    {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int m = nums.Length;
        int result = 0;
        int ptr = 0;
        int sum = 0;
        dic[0] = 1;
        while (ptr != m)
        {
            sum += nums[ptr];
            if (dic.ContainsKey(sum - k))
                result += dic[sum - k];
            if (dic.ContainsKey(sum))
                dic[sum]++;
            else
                dic[sum] = 1;
            ptr++;
        }
        return result;
    }
}