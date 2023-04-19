class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> myMap;
		for (int i = 0; i < nums.size(); ++i) {
			if (myMap.count(nums[i]) && i - myMap[nums[i]] <= k)
				return true;
			myMap[nums[i]] = i;
		}
		return false;
	}
};