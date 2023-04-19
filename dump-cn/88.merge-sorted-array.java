class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n)
    {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int ptr3 = m + n - 1;
        while (ptr3 != -1)
        {
            if (ptr1 != -1 && (ptr2 == -1 || nums1[ptr1] > nums2[ptr2]))
            {
                nums1[ptr3] = nums1[ptr1];
                ptr1--;
            }
            else
            {
                nums1[ptr3] = nums2[ptr2];
                ptr2--;
            }
            ptr3--;
        }
    }
}