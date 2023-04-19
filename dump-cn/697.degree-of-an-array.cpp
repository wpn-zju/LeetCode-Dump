class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		vector<int> count(50000, 0);
		for (int& i : nums)
			++count[i];
		vector<int> mxI;
		int mxF = 0;
		for (int i = 0; i < 50000; ++i) {
			if (count[i] > mxF) {
				mxF = count[i];
				mxI = { i };
			}
			else if (count[i] == mxF)
				mxI.push_back(i);
		}
		int shortest = nums.size();
		for (int i = 0; i < mxI.size(); ++i) {
			int ptr1 = 0;
			int ptr2 = nums.size() - 1;
			while (nums[ptr1] != mxI[i])
				++ptr1;
			while (nums[ptr2] != mxI[i])
				--ptr2;
			shortest = min(shortest, ptr2 - ptr1 + 1);
            if(shortest == mxF)
                break;
		}
		return shortest;
	}
};