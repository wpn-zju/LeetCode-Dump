class MyCalendar {
public:
	set<pair<int, int>> intervals;
	MyCalendar() {
		intervals.insert({ INT_MIN, INT_MIN + 1 });
		intervals.insert({ INT_MAX - 1,INT_MAX });
	}

	bool book(int s, int e) {
		auto index = intervals.lower_bound({ s,e });
		if (index->first < e || (--index)->second > s)
			return false;
		intervals.insert({ s, e });
		return true;
	}
};