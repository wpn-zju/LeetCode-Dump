class Solution {
    public int[] twoSum(int[] numbers, int target)
    {
        int[] result = new int[2];
        int m = numbers.length;
        int ptr1 = 0;
        int ptr2 = m - 1;
        while (ptr1 < ptr2)
        {
            if (numbers[ptr1] + numbers[ptr2] == target)
            {
                result[0] = ptr1 + 1;
                result[1] = ptr2 + 1;
                break;
            }
            else if (numbers[ptr1] + numbers[ptr2] > target)
                ptr2--;
            else
                ptr1++;
        }
        return result;
    }
}