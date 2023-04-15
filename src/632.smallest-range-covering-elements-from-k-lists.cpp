static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	struct CMP {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
			return a.first == b.first ? a.second < b.second : a.first < b.first;
		};
	};

	vector<int> smallestRange(vector<vector<int>>& nums) {
		if (nums.size() == 1)
			return { nums[0][0], nums[0][0] };
		vector<int> result{ -1000000,1000000 };
		vector<int> cur{ -1000000,1000000 };
		vector<int> ptrs(nums.size(), 0);
		set<pair<int, int>, CMP> data;
		for (int i = 0; i < nums.size(); ++i)
			data.insert({ nums[i][0],i });
		while (true) {
			auto e = data.end();
			cur = { data.begin()->first, (--e)->first };
			if (cur[1] - cur[0] < result[1] - result[0])
				result = cur;
			if (++ptrs[data.begin()->second] == nums[data.begin()->second].size())
				break;
			int toInsert = nums[data.begin()->second][ptrs[data.begin()->second]];
			int index = data.begin()->second;
			data.erase(data.begin());
			data.insert({ toInsert, index });
		}
		return result;
	}
};