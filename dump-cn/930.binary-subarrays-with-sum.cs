public class Solution {
    public int NumSubarraysWithSum(int[] A, int S)
    {
        int m = A.Length;
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int ptr = 0;
        int count = 0;
        int sum = 0;
        dic[0] = 1;
        while (ptr!=m)
        {
            sum += A[ptr];
            if (dic.ContainsKey(sum - S))
                count += dic[sum - S];
            if (dic.ContainsKey(sum))
                dic[sum]++;
            else
                dic[sum] = 1;
            ptr++;
        }
        return count;
    }
}