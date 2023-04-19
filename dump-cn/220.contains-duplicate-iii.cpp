class Solution {
public:
	int64_t getID(int64_t x, int64_t w) {
		return x < 0 ? (x + 1) / w - 1 : x / w;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (t < 0)
			return false;
		unordered_map<int64_t, int64_t> bucket;
		int64_t w = (int64_t)t + 1;
		for (int i = 0; i < nums.size(); ++i) {
			int64_t buc = getID(nums[i], w);
			if (bucket.count(buc))
				return true;
			if (bucket.count(buc - 1) && abs(nums[i] - bucket[buc - 1]) < w)
				return true;
			if (bucket.count(buc + 1) && abs(nums[i] - bucket[buc + 1]) < w)
				return true;
			bucket[buc] = (int64_t)nums[i];
			if (i >= k)
				bucket.erase(getID(nums[i - k], w));
		}
		return false;
	}
};