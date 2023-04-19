class Solution {
public:
	int numberLast = 0;
	vector<pair<int, int>> dataVec;
	Solution(int N, vector<int>& blacklist) {
		blacklist.push_back(-1);
		blacklist.push_back(N);
		sort(blacklist.begin(), blacklist.end());

		for (int i = 1; i < blacklist.size(); ++i) {
			if (blacklist[i] != blacklist[i - 1] + 1) {
				dataVec.push_back({ blacklist[i - 1] + 1,numberLast });
				numberLast += blacklist[i] - blacklist[i - 1] - 1;
			}
		}
	}

	int pick() {
		int r = rand() % numberLast;
		int start = 0;
		int end = dataVec.size() - 1;

		while (start < end) {
			int mid = start + (end - start >> 1);
			if (r < dataVec[mid].second)
				end = mid;
			else if (r == dataVec[mid].second)
				return dataVec[mid].first;
			else if (mid < dataVec.size() - 1 && r >= dataVec[mid + 1].second)
				start = mid + 1;
			else
				return dataVec[mid].first + (r - dataVec[mid].second);
		}

		return dataVec[start].first + (r - dataVec[start].second);
	}
};