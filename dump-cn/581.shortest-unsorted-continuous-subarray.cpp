class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
		vector<int> rMin(nums.size());
		vector<int> lMax(nums.size());
		int mn = INT_MAX, mx = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
			lMax[i] = mx = max(mx, nums[i]);
		for (int i = nums.size() - 1; i >= 0; --i)
			rMin[i] = mn = min(mn, nums[i]);
		int ptr1 = 0;
		int ptr2 = nums.size() - 1;
		while (ptr1 < nums.size() - 1 && lMax[ptr1] <= rMin[ptr1 + 1])
			++ptr1;
		while (ptr2 > 0 && lMax[ptr2 - 1] <= rMin[ptr2])
			--ptr2;
		return max(0, ptr2 - ptr1 + 1);
	}
};