static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class DinnerPlates {
public:
	int capa;
	set<int> empty;
	set<int, greater<int>> full;
	vector<stack<int>> data;

	DinnerPlates(int capacity) {
		capa = capacity;
	}

	void push(int val) {
		if (empty.empty()) {
			full.insert(data.size());
			data.push_back(stack<int>());
			data.back().push(val);
			if (data.back().size() < capa)
				empty.insert(data.size() - 1);
		}
		else {
			full.insert(*empty.begin());
			data[*empty.begin()].push(val);
			if (data[*empty.begin()].size() == capa)
				empty.erase(empty.begin());
		}
	}

	int pop() {
		if (full.empty())
			return -1;
		empty.insert(*full.begin());
		int result = data[*full.begin()].top();
		data[*full.begin()].pop();
		if (data[*full.begin()].empty())
			full.erase(full.begin());
		return result;
	}

	int popAtStack(int index) {
		if (index >= data.size() || data[index].empty())
			return -1;
		empty.insert(index);
		int result = data[index].top();
		data[index].pop();
		if (data[index].empty())
			full.erase(index);
		return result;
	}
};