class Solution {
public:
	string countOfAtoms(string formula) {
		formula.push_back('A');
		stack<unordered_map<string, int>> eleS;
		int ptr = 0;
		int curI = 0;
		string cur = "";
		unordered_map<string, int> curMap;
		while (ptr < formula.length()) {
			if (formula[ptr] == '(') {
				if (!cur.empty())
					curMap[cur] += curI ? curI : 1;
				eleS.push(curMap);
				curI = 0;
				cur.clear();
				curMap.clear();
			}
			else if (formula[ptr] == ')') {
				if (!cur.empty())
					curMap[cur] += curI ? curI : 1;
				curI = 0;
				++ptr;
				while (ptr < formula.length() && formula[ptr] <= '9' && formula[ptr] >= '0') {
					curI *= 10;
					curI += formula[ptr] - '0';
					++ptr;
				}
				--ptr;
				for (pair<string, int> p : curMap)
					eleS.top()[p.first] += p.second * (curI ? curI : 0);
				curI = 0;
				cur.clear();
				curMap = eleS.top();
				eleS.pop();
			}
			else if (formula[ptr] <= '9' && formula[ptr] >= '0') {
				curI *= 10;
				curI += formula[ptr] - '0';
			}
			else if (formula[ptr] <= 'Z' && formula[ptr] >= 'A') {
				if (!cur.empty())
					curMap[cur] += curI ? curI : 1;
				curI = 0;
				cur.clear();
				cur.push_back(formula[ptr]);
			}
			else {
				cur.push_back(formula[ptr]);
			}
			++ptr;
		}
		vector<pair<string, int>> vec;
		for (pair<string, int> p : curMap)
			vec.push_back(p);
		sort(vec.begin(), vec.end(), [](pair<string, int>& a, pair<string, int>& b) {return a.first < b.first; });
		string result = "";
		for (pair<string, int>& p : vec)
			result += p.first + (p.second == 1 ? "" : to_string(p.second));
		return result;
	}
};