static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
	void findSecretWord(vector<string>& wordlist, Master& master) {
		unordered_set<int> choose;
		vector<vector<int>> matchTable(wordlist.size(), vector<int>(wordlist.size()));
		for (int i = 0; i < wordlist.size(); ++i) {
			for (int j = i; j < wordlist.size(); ++j) {
				int len = 0;
				for (int k = 0; k < 6; ++k)
					if (wordlist[i][k] == wordlist[j][k])
						++len;
				matchTable[i][j] = matchTable[j][i] = len;
			}
		}
		for (int i = 0; i < 10; ++i) {
			int random = rand() % wordlist.size();
			while (choose.count(random))
                random = rand() % wordlist.size();		
			int result = master.guess(wordlist[random]);
			if (result == 6)
				return;
			for (int i = 0; i < wordlist.size(); ++i)
				if (matchTable[random][i] != result)
					choose.insert(i);
		}
	}
};