public class Solution {
    public IList<IList<int>> Subsets(int[] nums)
    {
        List<IList<int>> result = new List<IList<int>>();
        int size = nums.Length;
        int totalN = (int)Math.Pow(2, size);
        int tmp = 0;
        for(int i = 0; i < totalN; ++i)
        {
            List<int> lst = new List<int>();
            for(int j = 0; j < size; ++j)
            {
                uint tmp2 = (uint)tmp;
                tmp2 >>= j;
                tmp2 <<= 31;
                tmp2 >>= 31;
                if (tmp2 == 1)
                    lst.Add(nums[j]);
            }
            result.Add(lst);
            tmp++;
        }
        return result;
    }
}