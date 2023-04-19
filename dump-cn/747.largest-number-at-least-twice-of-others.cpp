class Solution {
public:
	int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
		vector<int> count(101, 0);
		for (int& i : nums)
			++count[i];
		int flag = -1;
		for (int i = 100; i >= 0; --i) {
			if (count[i]) {
				if (flag == -1) {
					if (count[i] > 1)
						return -1;
					else if (count[i] == 1)
						flag = i;
				}
				else {
					if (i << 1 > flag)
						return -1;
					else
						for (int n = 0; n < nums.size(); ++n)
							if (nums[n] == flag)
								return n;
				}			
			}
		}
		return -1;
	}
};