class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int mx = INT_MIN;
		int sum = 0;
		for (int& i : weights) {
			mx = max(mx, i);
			sum += i;
		}
		int start = mx;
		int end = sum;
		while (start < end) {
			int mid = start + (end - start >> 1);
			int count = 1;
			int cur = 0;
			for (int i = 0; i < weights.size(); ++i) {
				cur += weights[i];
				if (cur > mid) {
					cur = weights[i];
					++count;
				}
			}
			if (count > D)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};