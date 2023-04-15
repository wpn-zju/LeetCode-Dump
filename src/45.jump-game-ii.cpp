class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int ptr = 0;
		int count = 0;
		while (true) {
			if (nums[ptr] == 0)
				return 0;
			if (ptr + nums[ptr] >= nums.size() - 1) {
				count++;
				break;
			}
			int maxIndex = ptr;
			int max = nums[ptr] + ptr;
			int cur = nums[ptr];
			while (cur--) {
				ptr++;
				if (nums[ptr] + ptr > max) {
					max = nums[ptr] + ptr;
					maxIndex = ptr;
				}
			}
			ptr = maxIndex;
			count++;
		}
		return count;
	}
};