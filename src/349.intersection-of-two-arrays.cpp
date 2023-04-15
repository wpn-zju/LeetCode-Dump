class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_set<int> charSet1;
		unordered_set<int> charSet2;
		for (int i : nums1)
			charSet1.insert(i);
		for (int i : nums2)
			charSet2.insert(i);
		for (int i : charSet1)
			if (charSet2.count(i))
				result.push_back(i);
		return result;
	}
};