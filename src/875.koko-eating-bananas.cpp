class Solution {
public:
	int minEatingSpeed(vector<int>& weights, int D) {
		int mx = INT_MIN;
		double sum = 0;
		for (int& i : weights) {
			mx = max(mx, i);
			sum += i;
		}
		int start = ceil(sum / D);
		int end = mx;
		while (start < end) {
			int mid = start + (end - start >> 1);
			int count = 0;
			for (int& i : weights)
				count += ceil((double)i / mid);
			if (count > D)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};