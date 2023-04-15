class MyCalendarTwo {
public:
	map<int, int> count;

	bool book(int s, int e) {
		++count[s];
		--count[e];
		int sum = 0;
		for (pair<int, int> p : count) {
            sum += p.second;
			if (sum > 2) {
				--count[s];
				++count[e];
				return false;
			}
		}
		return true;
	}
};