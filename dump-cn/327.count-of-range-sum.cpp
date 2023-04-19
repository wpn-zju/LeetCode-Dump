class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int count = 0;
		multiset<int64_t> searchSet{ 0 };
		int64_t sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			auto r = searchSet.upper_bound(sum - lower);
			auto l = searchSet.lower_bound(sum - upper);
			count += distance(l, r);
            searchSet.insert(sum);
		}
		return count;
	}
};