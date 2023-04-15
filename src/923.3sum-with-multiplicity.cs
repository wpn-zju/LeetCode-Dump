public class Solution {
    public int ThreeSumMulti(int[] A, int target)
    {
        Array.Sort(A);
        int m = A.Length;
        int ptr1 = 0;
        int count = 0;
        while(ptr1 != m)
        {
            int targetN = target - A[ptr1];
            int ptr2 = ptr1 + 1;
            int ptr3 = m - 1;
            while (ptr2 < ptr3)
            {
                if (A[ptr2] + A[ptr3] == targetN)
                {
                    if (A[ptr2] == A[ptr3])
                    {
                        int countN = ptr3-ptr2+1;
                        count += (countN - 1) * countN / 2;
                        count %= 1000000007;
                        break;
                    }
                    else
                    {
                        int countL = 1;
                        int countR = 1;
                        while (ptr2 < ptr3 && A[ptr2 + 1] == A[ptr2])
                        {
                            ptr2++;
                            countL++;
                        }
                        ptr2++;
                        while (ptr3 > ptr2 && A[ptr3 - 1] == A[ptr3])
                        {
                            ptr3--;
                            countR++;
                        }
                        ptr3--;
                        count += countL * countR;
                        count %= 1000000007;
                    }
                }
                else if (A[ptr2] + A[ptr3] > targetN)
                    ptr3--;
                else
                    ptr2++;
            }
            ptr1++;
        }
        return count;
    }
}