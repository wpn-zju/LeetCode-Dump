class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int score = 0;
		int cur = 0;
		for (int i = 0; i < k - 1; ++i)
			cur += calories[i];
		for (int i = k - 1; i < calories.size(); ++i) {
			cur += calories[i];
			if (cur < lower)
				--score;
			else if (cur > upper)
				++score;
			cur -= calories[i - k + 1];
		}
		return score;
	}
};