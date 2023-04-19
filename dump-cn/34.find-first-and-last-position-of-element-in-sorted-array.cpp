class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size())
            return vector<int>{ -1, -1 };
        int ptr1 = -1;
        int ptr2 = nums.size();
        int x = (ptr1 + ptr2) / 2;
        while (nums[x] != target && ptr1 < ptr2 - 1){
            if (nums[x] > target)
                ptr2 = x;
            else
                ptr1 = x;
            x = (ptr1 + ptr2) / 2;
        }
        if (nums[x] != target)
            return vector<int>{ -1, -1 };
        ptr1 = ptr2 = x;
        while (ptr1 > 0 && nums[ptr1 - 1] == target)
            ptr1--;
        while (ptr2 < nums.size() - 1 && nums[ptr2 + 1] == target)
            ptr2++;
        return vector<int>{ ptr1, ptr2 };
    }
};