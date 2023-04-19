static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int>* data;
	Solution(vector<int>& nums) {
		data = &nums;
	}

	int pick(int target) {
		int count = 0;
		int result = -1;
		for (int i = 0; i < data->size(); ++i)
			if ((*data)[i] == target)
				result = rand() % ++count ? result : i;
		return result;
	}
};