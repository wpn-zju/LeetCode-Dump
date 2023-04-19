public class Solution {
    public int SubarraysDivByK(int[] A, int K)
    {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int m = A.Length;
        int result = 0;
        int ptr = 0;
        int sum = 0;
        dic[0] = 1;
        while (ptr != m)
        {
            sum += A[ptr];
            int mod = sum%K<0?sum%K+K:sum%K;
            if (dic.ContainsKey(mod))
                result += dic[mod];
            if (dic.ContainsKey(mod))
                dic[mod]++;
            else
                dic[mod] = 1;
            ptr++;
        }
        return result;
    }
}