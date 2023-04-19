class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		heaters.push_back(INT_MIN);
		heaters.push_back(INT_MAX);
		sort(heaters.begin(), heaters.end());
		int result = 0;
		for (int& i : houses) {
			int start = 0;
			int end = heaters.size() - 1;
			while (start < end) {
				int mid = start + (end - start >> 1);
				if (heaters[mid] < i)
					start = mid + 1;
				else
					end = mid;
			}
			result = max((int64_t)result, min((int64_t)i - heaters[start - 1], (int64_t)heaters[start] - i));
		}
		return result;
	}
};