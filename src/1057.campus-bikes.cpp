class Solution {
public:
	vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		vector<int> result(workers.size());
		vector<bool> selectedB = vector<bool>(bikes.size(), false);
		list<pair<int, list<pair<int, int>>>> data;
		auto func1 = [](pair<int, int>& a, pair<int, int>& b) {
			return a.second == b.second ? a.first < b.first : a.second < b.second;
		};
		auto func2 = [](pair<int, list<pair<int, int>>>& a, pair<int, list<pair<int, int>>>& b) {
			if (a.second.begin()->second != b.second.begin()->second)
				return a.second.begin()->second < b.second.begin()->second;
			return a.first < b.first;
		};
		for (int i = 0; i < workers.size(); ++i) {
			data.push_back({ i, list<pair<int, int>>() });
			for (int j = 0; j < bikes.size(); ++j)
				data.back().second.push_back({ j, abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]) });
			data.back().second.sort(func1);
		}
		data.sort(func2);
		for (int i = 0; i < workers.size(); ++i) {
			result[data.front().first] = data.front().second.front().first;
			selectedB[data.front().second.front().first] = true;
            data.pop_front();
			for (auto it = data.begin(); it != data.end(); ++it)
				while (!it->second.empty() && selectedB[it->second.front().first])
					it->second.pop_front();
			data.sort(func2);
		}
		return result;
	}
};