class Solution {
public:
	vector<string> expand(string S) {
		vector<string> result;
		vector<string> data;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] == '{') {
				data.push_back({});
				while (S[i] != '}') {
					data.back().push_back(S[i + 1]);
					i += 2;
				}
				sort(data.back().begin(), data.back().end());
			}
			else
				data.push_back({ S[i] });
		}
		S.clear();
		dfsEX(result, S, data, 0);
		return result;
	}

	void dfsEX(vector<string>& result, string& cur, vector<string>& data, int index) {
		if (index == data.size()) {
			result.push_back(cur);
			return;
		}
		for (char& c : data[index]) {
			cur.push_back(c);
			dfsEX(result, cur, data, index + 1);
			cur.pop_back();
		}
	}
};