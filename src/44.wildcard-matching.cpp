class Solution {
public:
    struct HashFunc {
		size_t operator()(const pair<int, int>& key) const {
			return (hash<unsigned long long>()(((unsigned long long)key.first << 32) + key.second));
		}
	};

	struct EqualKey {
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};
    
    unordered_map<pair<int, int>, bool, HashFunc, EqualKey> matchMap;
    
	bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
	}
    
	bool isMatch(string& s, string& p, int starts, int startp) {
		if (matchMap.count(pair<int, int>(starts, startp)))
			return matchMap[pair<int, int>(starts, startp)];
		int m = s.length() - starts;
		int n = p.length() - startp;
		if (m == 0 && n == 0)
			matchMap[pair<int, int>(starts, startp)] = true;
		else if (n == 0)
			matchMap[pair<int, int>(starts, startp)] = false;
		else if (p[startp] == '*') {
			if (n > 1 && p[startp + 1] == '*')
				matchMap[pair<int, int>(starts, startp)] = isMatch(s, p, starts, startp + 1);
			else {
				int ptr1 = 0;
				bool result = false;
				while (!result && ptr1 != m) {
					result |= matchMap[pair<int, int>(starts + ptr1 + 1, startp + 1)] = isMatch(s, p, starts + ptr1 + 1, startp + 1);
					ptr1++;
				}
				result |= matchMap[pair<int, int>(starts, startp)] = isMatch(s, p, starts, startp + 1);
				matchMap[pair<int, int>(starts, startp)] = result;
			}
		}
		else if (m == 0)
			matchMap[pair<int, int>(starts, startp)] = false;
		else if (s[starts] == p[startp] || p[startp] == '?')
			matchMap[pair<int, int>(starts, startp)] = isMatch(s, p, starts + 1, startp + 1);
		else
			matchMap[pair<int, int>(starts, startp)] = false;
		return matchMap[pair<int, int>(starts, startp)];
	}
};