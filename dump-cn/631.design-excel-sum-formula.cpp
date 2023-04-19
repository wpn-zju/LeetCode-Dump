vector<int> extractStr(string& input) {
	vector<int> result(4, 0);
	result[1] = input[0] - 'A';
	int len = 0;
	int ptr = 1;
	while (ptr < input.length() && input[ptr] <= '9' && input[ptr] >= '0') {
		len *= 10;
		len += input[ptr++] - '0';
	}
	result[0] = len - 1;
	if (ptr == input.length()) {
		result[2] = result[0];
		result[3] = result[1];
		return result;
	}
    ++ptr;
	result[3] = input[ptr++] - 'A';
	len = 0;
	while (ptr < input.length() && input[ptr] <= '9' && input[ptr] >= '0') {
		len *= 10;
		len += input[ptr++] - '0';
	}
	result[2] = len - 1;
	return result;
}

class Excel {
public:
	int H;
	unordered_map<int, vector<vector<int>>> store;
	vector<vector<int>> data;
	Excel(int H, char W) {
		this->H = H;
		data = vector<vector<int>>(H, vector<int>(W - 'A' + 1, 0));
	}

	void set(int r, char c, int v) {
		if (store.count((r - 1)*H + (c - 'A')))
			store.erase((r - 1)*H + (c - 'A'));
		data[r - 1][c - 'A'] = v;
	}

	int get(int r, char c) {
		if(!store.count((r - 1)*H + (c - 'A')))
			return data[r - 1][c - 'A'];
		int sum = 0;
		for (vector<int>& vec : store[(r - 1)*H + (c - 'A')])
			for (int i = vec[0]; i <= vec[2]; ++i)
				for (int j = vec[1]; j <= vec[3]; ++j)
					sum += get(i + 1, j + 'A');
		return sum;
	}

	int sum(int r, char c, vector<string> strs) {
		int sum = 0;
		if (store.count((r - 1)*H + (c - 'A')))
			store[(r - 1)*H + (c - 'A')].clear();
		for (string& str : strs)
			store[(r - 1)*H + (c - 'A')].push_back(extractStr(str));
		return get(r, c);
	}
};