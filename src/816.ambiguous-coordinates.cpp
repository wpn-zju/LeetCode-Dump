class Solution {
public:
	vector<string> ambiguousCoordinates(string S) {
		S = S.substr(1, S.size() - 2);
		vector<string> result;
		for (int i = 1; i < S.size(); ++i) {
			string sub1 = S.substr(0, i);
			string sub2 = S.substr(i, S.size() - i);
			vector<string> sub1Strs;
			vector<string> sub2Strs;
			if (sub1.front() != '0' || sub1 == "0")
				sub1Strs.push_back(sub1);
			if (sub1.back() != '0') {
				int ptr = 0;
				while (sub1[ptr] == '0')
					++ptr;
				if (ptr == 0)
					for (int j = max(1, ptr); j < sub1.size(); ++j)
						sub1Strs.push_back(sub1.substr(0, j) + '.' + sub1.substr(j));
				else if (sub1.size() > 1)
					sub1Strs.push_back("0." + sub1.substr(1));
			}
			if (sub2.front() != '0' || sub2 == "0")
				sub2Strs.push_back(sub2);
			if (sub2.back() != '0') {
				int ptr = 0;
				while (sub2[ptr] == '0')
					++ptr;
				if (ptr == 0)
					for (int j = max(1, ptr); j < sub2.size(); ++j)
						sub2Strs.push_back(sub2.substr(0, j) + '.' + sub2.substr(j));
				else if (sub2.size() > 1)
					sub2Strs.push_back("0." + sub2.substr(1));
			}
			for (int j = 0; j < sub1Strs.size(); ++j)
				for (int k = 0; k < sub2Strs.size(); ++k)
					result.push_back('(' + sub1Strs[j] + ", " + sub2Strs[k] + ')');
		}
		return result;
	}
};