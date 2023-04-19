class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> mySet;
		for (int& i : nums)
			if (mySet.count(i))
				return true;
			else
				mySet.insert(i);
		return false;
	}
};