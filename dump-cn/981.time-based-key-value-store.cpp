static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class TimeMap {
public:
	unordered_map<string, vector<pair<int, string>>> data;
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		data[key].push_back({ timestamp, value });
	}

	string get(string key, int timestamp) {
		vector<pair<int, string>>& vec = data[key];
		int start = 0;
		int end = vec.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (vec[mid].first > timestamp)
				end = mid;
			else
				start = mid + 1;
		}
		return vec[start].first <= timestamp ? vec[start].second : start ? vec[start - 1].second : "";
	}
};