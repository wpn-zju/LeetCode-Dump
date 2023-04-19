    public class NumArray
    {
        public int[] sumArray;

        public NumArray(int[] nums)
        {
            sumArray = new int[nums.Length];
            int sum = 0;
            for(int i =0;i<nums.Length;++i)
                sumArray[i] = sum += nums[i];
        }

        public int SumRange(int i, int j)
        {
            return i == 0 ? sumArray[j] : sumArray[j] - sumArray[i - 1];
        }
    }

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.SumRange(i,j);
 */