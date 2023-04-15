static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<string> wordsAbbreviation(vector<string>& dict) {
		unordered_map<string, int> uMap;
		unordered_map<string, int> length;
		for (int i = 0; i < dict.size(); ++i)
			uMap[dict[i]] = i;
		sort(dict.begin(), dict.end(), [&length](string& a, string& b) {
			if (a.length() != b.length())
				return a.length() < b.length();
			else if (a.back() != b.back())
				return a.back() < b.back();
			for (int i = 0; i < a.length() - 1; ++i)
				if (a[i] != b[i]) {
					length[a] = max(length[a], i);
					length[b] = max(length[b], i);
					return a[i] < b[i];
				}
			return false;
		});
		unordered_set<string> s;
		vector<string> result(dict.size());
		for (int i = 0; i < dict.size(); ++i) {
			if (dict[i].length() < 4)
				result[uMap[dict[i]]] = dict[i];
			else {
				string tmp = dict[i].substr(0, length[dict[i]] + 1)
					+ to_string(dict[i].length() - length[dict[i]] - 2)
					+ dict[i].back();
				if (tmp.length() >= dict[i].length())
					result[uMap[dict[i]]] = dict[i];
				else if (s.count(tmp))
					result[uMap[dict[i]]] = dict[i];
				else {
					result[uMap[dict[i]]] = tmp;
					s.insert(tmp);
				}
			}
		}
		return result;
	}
};