class Solution {
public:
    bool canJump(vector<int>& nums) {
        return jump(nums);
    }
    
    int jump(vector<int>& nums) {
		if (nums.size() < 2)
			return 1;
		int ptr = 0;
		int count = 0;
		while (true) {
            int prev = ptr;
			if (nums[ptr] == 0)
				return 0;
			// 防止溢出
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
            if(prev == maxIndex)
                return 0;            
			ptr = maxIndex;
			count++;
		}
		return count;
	}
};