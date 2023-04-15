class FreqStack {
public:
	int mx;
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> data;
	FreqStack() {
		mx = 0;
	}

	void push(int x) {
		mx = max(mx, ++freq[x]);
		data[freq[x]].push(x);
	}

	int pop() {
		int result = data[mx].top();
		data[mx].pop();
		if (data[mx].empty())
			data.erase(mx--);
		--freq[result];
		return result;
	}
};