class Solution {
public:
		void nextPermutation(vector<int>& nums) {
            if(nums.size()<2)
                return;
			int ptr1 = nums.size() - 1;
			while (ptr1 > 0 && nums[ptr1] <= nums[ptr1 - 1])
				ptr1--;
			ptr1--;
			if (ptr1 < 0) {
				reverse(nums.begin(), nums.end());
				return;
			}
			int ptr2 = ptr1 + 1;
			while (ptr2 < nums.size() && nums[ptr2] > nums[ptr1])
				ptr2++;
			ptr2--;
			swap(nums[ptr1], nums[ptr2]);
			reverse(nums.begin() + ptr1 + 1, nums.end());
		}
};