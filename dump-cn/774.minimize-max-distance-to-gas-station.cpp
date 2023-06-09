static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	double minmaxGasDist(vector<int>& stations, int K) {
		int mxDiff = -1;
		for (int i = 1; i < stations.size(); ++i)
			mxDiff = max(mxDiff, stations[i] - stations[i - 1]);
		double start = floor(mxDiff / (K + 1));
		double end = ceil(mxDiff);
		while (abs(start - end) > 1e-6) {
			double mid = start + (end - start) / 2;
			int count = 0;
			for (int i = 1; i < stations.size(); ++i)
				count += ceil(((double)stations[i] - stations[i - 1]) / mid) - 1;
			if (count > K)
				start = mid + 1e-6;
			else
				end = mid;
		}
		return start;
	}
};