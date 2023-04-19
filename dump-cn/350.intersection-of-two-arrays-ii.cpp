class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> charMap;
		for (int i : nums1)
			charMap[i]++;
		for (int i : nums2)
			if (charMap[i] > 0) {
				charMap[i]--;
				result.push_back(i);
			}
		return result;
	}
};