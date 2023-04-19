class Solution {
public:
	int minSwaps(vector<int>& data) {
		int t = 0;
		for (int& i : data)
			t += i;
		int cur = 0;
		for (int i = 0; i < t; ++i)
			cur += data[i];
		int result = t - cur;
		for (int i = t; i < data.size(); ++i) {
			cur += data[i];
            cur -= data[i - t];
			result = min(result, t - cur);
		}
		return result;
	}
};