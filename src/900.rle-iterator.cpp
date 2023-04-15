class RLEIterator {
public:
	vector<int>::iterator it;
	vector<int>::iterator end;
	RLEIterator(vector<int>& A) {
		it = A.begin();
		end = A.end();
	}

	int next(int n) {
		while (it != end && n > *it) {
			n -= *it;
			it += 2;
		}
		if (it == end)
			return -1;
		*it -= n;
		return *std::next(it);
	}
};