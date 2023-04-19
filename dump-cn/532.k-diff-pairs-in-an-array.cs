public class Solution {
    public int FindPairs(int[] nums, int k)
    {
        if(k<0)
            return 0;
        int m = nums.Length;
        HashSet<int> set = new HashSet<int>();
        HashSet<int> matched = new HashSet<int>();
        int count = 0;
        foreach(int i in nums)
        {
            if (set.Contains(i - k))
            {
                if(!matched.Contains(i - k))
                {
                    count++;
                    matched.Add(i - k);
                }
            }
            if (set.Contains(i + k))
            {
                if (!matched.Contains(i))
                {
                    count++;
                    matched.Add(i);
                }
            }
            set.Add(i);
        }
        return count;
    }
}