class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		int result = 0;
		unordered_map<int, int> count;
		for (int& i : arr) {
			count[i] = count[i - difference] + 1;
			result = max(result, count[i]);
		}
		return result;
	}
};