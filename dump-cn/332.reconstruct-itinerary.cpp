class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		set<string> dic;
		unordered_map<string, int> str2Int;
		unordered_map<int, string> int2Str;
		for (vector<string>& vec : tickets)
			for (string& str : vec)
				if (!dic.count(str))
					dic.insert(str);
		int count = 0;
		for (auto it = dic.begin(); it != dic.end(); ++it) {
			str2Int[*it] = count;
			int2Str[count] = *it;
			++count;
		}
		vector<int> result{ str2Int["JFK"] };
		vector<int> output;
		vector<vector<pair<int, bool>>> tGraphInt(count + 1);
		for (vector<string>& vec : tickets)
			tGraphInt[str2Int[vec[0]]].push_back({ str2Int[vec[1]],false });
		for (vector<pair<int, bool>>& vec : tGraphInt)
			sort(vec.begin(), vec.end());
		dfsFindItinerary(output, result, tGraphInt, str2Int["JFK"], tickets.size());
		vector<string> outputStr;
		for (int i = 0; i < output.size(); ++i)
			outputStr.push_back(int2Str[output[i]]);
		return outputStr;
	}

	void dfsFindItinerary(vector<int>& output, vector<int>& result, vector<vector<pair<int, bool>>>& tGraphInt, int cur, int last) {
		if (!output.empty())
			return;
		if (last == 0) {
			output = result;
			return;
		}
		for (pair<int, bool>& i : tGraphInt[cur]) {
			if (!i.second) {
				i.second = true;
				result.push_back(i.first);
				dfsFindItinerary(output, result, tGraphInt, i.first, last - 1);
				result.pop_back();
				i.second = false;
			}
		}
	}
};