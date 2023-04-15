public class Solution {
    public int NumRescueBoats(int[] people, int limit)
    {
        List<int> list = people.ToList();
        list.Sort();
        int count = 0;
        int ptr1 = list.Count - 1;
        int ptr2 = 0;
        while (ptr1 > ptr2)
        {
            if (list[ptr1] + list[ptr2] <= limit)
            {
                ptr1--;
                ptr2++;
            }
            else
                ptr1--;
            count++;
        }
        return ptr1==ptr2?count+1:count;
    }
}