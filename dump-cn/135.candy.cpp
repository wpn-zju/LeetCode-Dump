static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies(ratings.size(), -1);
		vector<int> valley;
		for (int i = 0; i < ratings.size(); ++i) {
			if ((i == 0 || ratings[i - 1] >= ratings[i]) && (i == ratings.size() - 1 || ratings[i + 1] >= ratings[i])) {
				candies[i] = 1;
				valley.push_back(i);
			}
		}
		for (int i = 0; i < valley.size(); ++i) {
			int ptr1 = valley[i] - 1;
			int ptr2 = valley[i] + 1;
			int cur = 1;
			while (ptr1 >= 0 && ratings[ptr1] > ratings[ptr1 + 1] && candies[ptr1] < cur + 1)
				candies[ptr1--] = ++cur;
			cur = 1;
			while (ptr2 < ratings.size() && ratings[ptr2] > ratings[ptr2 - 1] && candies[ptr2] < cur + 1)
				candies[ptr2++] = ++cur;
		}
		int result = 0;
		for (int& i : candies)
			result += i;
		return result;
	}
};