class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		int result = 0;
		vector<int> count(121, 0);
		for (int& i : ages)
			++count[i];
		for (int i = 1; i < count.size(); ++i) {
			int n = 0;
			for (int j = 1; j <= i; ++j)
				if (2 * j - 14 > i)
					n += count[j];
            n -= 1;
			result += max(0, n * count[i]);
		}
		return result;
	}
};