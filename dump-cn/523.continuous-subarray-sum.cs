public class Solution {
    public bool CheckSubarraySum(int[] nums, int k)
    {
        for (int i = 0; i < nums.Length - 1; ++i)
            if (nums[i] == 0 && nums[i + 1] == 0) return true;
        if (k == 0) return false;
        if (k < 0)
            k = -k;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int m = nums.Length;
        int ptr = 0;
        int sum = 0;
        dic[0] = -1;
        while (ptr != m)
        {
            sum += nums[ptr];
            if (dic.ContainsKey(sum % k) && dic[sum % k] != ptr - 1)
                return true;
            if (!dic.ContainsKey(sum % k))
                dic[sum % k] = ptr;
            ptr++;
        }
        return false;
    }
}