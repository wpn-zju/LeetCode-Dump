class Solution {
public:
	int maxWidthRamp(vector<int>& A) {
		vector<pair<int, int>> data;
		for (int i = 0; i < A.size(); ++i)
			data.push_back({ A[i],i });
		sort(data.begin(), data.end());
		int ptr = 0;
		int result = 0;
		for (int i = 1; i < data.size(); ++i) {
			if (data[i - 1].second < data[ptr].second)
				ptr = i - 1;
			result = max(result, data[i].second - data[ptr].second);
		}
		return result;
	}
};