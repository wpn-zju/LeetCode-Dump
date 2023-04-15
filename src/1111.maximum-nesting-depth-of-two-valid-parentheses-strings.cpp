class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> store(seq.length());
		int mx = 0;
		int cur = 1;
		for (int i = 0; i < seq.length(); ++i)
			if (seq[i] == '(')
				mx = max(mx, store[i] = cur++);
			else
				store[i] = --cur;
		for (int& i : store)
			i = i > mx / 2;
		return store;
	}
};