

int findDuplicate(int* nums, int numsSize){
        int a = 0, b = 0;
        do
        {
            a = nums[a];
            b = nums[b];
            b = nums[b];
        } while (a != b);
        int c = 0;
        while (a != c)
        {
            a = nums[a];
            c = nums[c];
        }
        return a;
}

