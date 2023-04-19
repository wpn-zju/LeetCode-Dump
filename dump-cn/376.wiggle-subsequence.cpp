class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int ptr = 0;
		while (ptr < nums.size() - 1 && nums[ptr] == nums[ptr + 1])
			++ptr;
		if (ptr == nums.size() - 1)
			return 1;
		int count = ptr;
		bool tag = nums[ptr] > nums[ptr + 1]; // F
		int last = ptr + 1;
		for (int i = ptr + 2; i < nums.size(); ++i) {
            if(nums[i] == nums[last])
                ++count;
			else if (tag ^ (nums[i] < nums[last])) {
				last = i;
				tag = !tag;
			}
			else {
				last = i;
				++count;
			}
		}
		return nums.size() - count;
	}
};