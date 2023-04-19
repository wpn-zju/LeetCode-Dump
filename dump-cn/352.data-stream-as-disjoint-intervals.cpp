static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class SummaryRanges {
public:
	set<int> data;

	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		data.insert(val);
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> result;
		set<int>::iterator prev = data.begin();
		set<int>::iterator cur = prev;
		int last = *cur++;
		for (; cur != data.end(); ++prev, ++cur) {
			if (*cur != *prev + 1) {
				result.push_back({ last, *prev });
				last = *cur;
			}
		}
		result.push_back({ last, *prev });
		return result;
	}
};