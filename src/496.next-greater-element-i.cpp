class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> match;
		stack<int> s;
		for (int i = 0; i < nums2.size(); ++i) {
			while (!s.empty() && s.top() < nums2[i]) {
				match[s.top()] = nums2[i];
				s.pop();
			}
			s.push(nums2[i]);
		}
		while (!s.empty()) {
			match[s.top()] = -1;
			s.pop();
		}
		vector<int> result(nums1.size());
		for (int i = 0; i < nums1.size(); ++i)
			result[i] = match[nums1[i]];
		return result;
	}
};