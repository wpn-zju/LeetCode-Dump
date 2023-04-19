class Solution {
public:
	int maximizeSweetness(vector<int>& weights, int D) {
		++D;
		int mn = INT_MAX;
		int sum = 0;
		for (int& i : weights) {
			mn = min(mn, i);
			sum += i;
		}
		int start = mn;
		int end = sum / D;

		while (start < end) {
			int mid = start + (end - start >> 1);
			int count = 1;
			int cur = 0;
			for (int& i : weights) {
				cur += i;
				if (cur > mid) {
					cur = 0;
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