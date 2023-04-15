class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		map<char, int> targetMap;
		for (char& c : target)
			++targetMap[c];
		vector<map<char, int>> data;
		for (int i = 0; i < stickers.size(); ++i) {
			map<char, int> tmp;
			for (char& c : stickers[i])
				if (targetMap.count(c))
					++tmp[c];
			if (!tmp.empty())
				data.push_back(tmp);
		}

		map<char, int> indexMap;
		string targetString = "";
		for (pair<char, int> p : targetMap) {
			indexMap[p.first] = targetString.length();
			targetString.push_back(p.second);
		}

		set<string> data2;
		for (map<char, int>& m : data) {
			string cur(targetString.length(), 0);
			for (pair<char, int> p : m)
				cur[indexMap[p.first]] = p.second;
			data2.insert(cur);
		}
        
		vector<string> data3(data2.begin(), data2.end());
        sort(data3.begin(), data3.end(), [](string& a, string& b) {
			int sum1 = 0;
			int sum2 = 0;
			for (char& c : a)
				sum1 += c;
			for (char& c : b)
				sum2 += c;
			return sum1 > sum2;
		});
        
		string tmp(targetString.length(), 0);
		int result = INT_MAX;
		int t = 0;
		int s = 0;
		dfsMST(result, data3, targetString, t, tmp, s);
		return result == INT_MAX ? -1 : result;
	}
    
	bool doneMST(string& target, string& cur) {
		for (int i = 0; i < target.length(); ++i)
			if (target[i] > cur[i])
				return false;
		return true;
	}

	int enough(string& data, string& cur, string& target) {
		int result = 0;
		for (int i = 0; i < target.length(); ++i)
			if (data[i])
				result = max(result, (int)ceil(((double)target[i] - cur[i]) / data[i]));
		return result;
	}

	void dfsMST(int& result, vector<string>& data, string& target, int& num, string& cur, int& startIndex) {
		if (num >= result)
			return;
		if (doneMST(target, cur)) {
			result = min(result, num);
			return;
		}
		if (startIndex < data.size()) {
			int needed = enough(data[startIndex], cur, target);
			for (int i = 0; i < data[startIndex].length(); ++i)
				cur[i] += data[startIndex][i] * needed;
			num += needed;
			++startIndex;
			dfsMST(result, data, target, num, cur, startIndex);
			--startIndex;
			while (needed--) {
				for (int i = 0; i < data[startIndex].length(); ++i)
					cur[i] -= data[startIndex][i];
				--num;
				++startIndex;
				dfsMST(result, data, target, num, cur, startIndex);
				--startIndex;
			}
		}
	}
};