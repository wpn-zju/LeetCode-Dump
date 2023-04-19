static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3)
			return false;
		int n1 = INT_MAX;
		int n2 = INT_MAX;
		for (int& i : nums)
			if (i <= n1)
				n1 = i;
			else if (i <= n2)
				n2 = i;
			else
				return true;
		return false;
	}
};