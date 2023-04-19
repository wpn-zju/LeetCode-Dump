class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		vector<vector<int>> result{ {arr[0],arr[1]} };
		for (int i = 1; i < arr.size() - 1; ++i) {
			if (arr[i + 1] - arr[i] < result.back().back() - result.back().front())
				result = { {arr[i], arr[i + 1]} };
			else if (arr[i + 1] - arr[i] == result.back().back() - result.back().front())
				result.push_back({ arr[i], arr[i + 1] });
		}
		return result;
	}
};