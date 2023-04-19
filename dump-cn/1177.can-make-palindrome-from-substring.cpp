static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
		vector<bool> result(queries.size(), false);
		vector<int> store(s.length() + 1, 0);
		for (int i = 0; i < s.size(); ++i)
			store[i + 1] = store[i] ^ (1 << s[i] - 'a');
		for (int i = 0; i < queries.size(); ++i) {
			int diff = store[queries[i][1] + 1] ^ store[queries[i][0]];
			int count = 0;
			for (int i = 0; i < 26; ++i)
				count += !!(diff & (1 << i));
			result[i] = ((queries[i][1] - queries[i][0]) & 1) ? queries[i][2] << 1 >= count : queries[i][2] << 1 >= count - 1;
		}
		return result;
	}
};