class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		vector<int> mxA(arr.size());
		vector<int> mnA(arr.size());
		int mx = INT_MIN;
		for (int i = 0; i < arr.size(); ++i)
			mxA[i] = mx = max(mx, arr[i]);
		int mn = INT_MAX;
		for (int i = arr.size() - 1; i >= 0; --i)
			mnA[i] = mn = min(mn, arr[i]);
		int result = 0;
		for (int i = 0; i < arr.size(); ++i)
			if (i == arr.size() - 1 || mxA[i] <= mnA[i + 1])
				++result;
		return result;
	}
};