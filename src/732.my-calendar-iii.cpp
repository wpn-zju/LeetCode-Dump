class MyCalendarThree {
public:
	map<int, int> count;

	int book(int s, int e) {
		++count[s];
		--count[e];
        int result = 0;
		int sum = 0;
		for (pair<int, int> p : count)
			result = max(result, sum += p.second);
		return result;
	}
};