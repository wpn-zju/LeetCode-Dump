class Solution {
public:
    // 并查集题一定要注意找索引都带上一层find()
	class UnionFindAccount {
	public:
		int count;
		unordered_map<int, int> accountMap;

		UnionFindAccount(int n) {
			count = n;
			for (int i = 0; i < n; ++i)
				accountMap[i] = i;
		}

		int find(int& x) {
			if (accountMap[x] == x)
				return x;
			return accountMap[x] = find(accountMap[x]);
		}

		void unionEle(int& x, int& y) {
			int px = find(x);
			int py = find(y);
			if (px != py) {
				count--;
				accountMap[py] = px;
			}
		}
	};

	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		unordered_map<int, string> nameMap;
		map<string, int> emailMap;
		UnionFindAccount ufa(accounts.size());
		for (int i = 0; i < accounts.size(); ++i) {
			nameMap[i] = accounts[i][0];
			for (int j = 1; j < accounts[i].size(); ++j) {
				if (emailMap.count(accounts[i][j]))
					ufa.unionEle(emailMap[accounts[i][j]], i);
				else
					emailMap[accounts[i][j]] = i;
			}
		}

		vector<vector<string>> result(ufa.count, vector<string>());
		unordered_map<int, int> resultMap;
		int count = 0;
		for (pair<int, int> p : ufa.accountMap) {
			if (!resultMap.count(ufa.find(p.second))) {
				result[count].push_back(nameMap[ufa.find(p.second)]);
				resultMap[ufa.find(p.second)] = count;
				count++;
			}
		}

		for (pair<string, int> kvp : emailMap)
			result[resultMap[ufa.find(ufa.accountMap[kvp.second])]].push_back(kvp.first);

		return result;
	}
};