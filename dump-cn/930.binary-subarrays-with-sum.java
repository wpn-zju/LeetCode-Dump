class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int m = A.length;
        HashMap<Integer, Integer> dic = new HashMap<Integer, Integer>();
        int ptr = 0;
        int count = 0;
        int sum = 0;
        dic.put(0,1);
        while (ptr!=m)
        {
            sum += A[ptr];
            count += dic.getOrDefault(sum - S, 0);
            dic.put(sum, dic.getOrDefault(sum, 0) + 1);
            ptr++;
        }
        return count;
    }
}