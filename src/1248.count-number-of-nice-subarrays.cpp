static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int count = 0;
		int countOdd = 0;
		int ptr1 = -1;
		int ptr2 = 0;
		while (ptr2 < nums.size()) {
			if (nums[ptr2] & 1) {
				++countOdd;
				if (countOdd == k) {
					int l = 1, r = 1;
					++ptr1;
					while (!(nums[ptr1] & 1)) {
						++ptr1;
						++l;
					}
					++ptr2;
					while (ptr2 < nums.size() && !(nums[ptr2] & 1)) {
						++ptr2;
						++r;
					}
					count += l * r;
					--countOdd;
					--ptr2;
				}
			}
			++ptr2;
		}
		return count;
	}
};