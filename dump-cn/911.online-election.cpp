static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class TopVotedCandidate {
public:
	vector<vector<int>> resultData;
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		resultData.push_back({ -1, -1, 0 });
		unordered_map<int, int> data;
		for (int i = 0; i < persons.size(); ++i)
			if (++data[persons[i]] >= resultData.back()[2])
				resultData.push_back({ times[i], persons[i],data[persons[i]] });
	}

	int q(int t) {
		int start = 1;
		int end = resultData.size() - 1;
		while (start < end) {
			int mid = end - (end - start >> 1);
			if (resultData[mid][0] > t)
				end = mid - 1;
			else
				start = mid;
		}
		return resultData[start][1];
	}
};