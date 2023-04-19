class ValidWordAbbr {
public:
	unordered_set<string> dicSet;
	unordered_map<string, int> abbrSet;
	ValidWordAbbr(vector<string>& dictionary) {
		for (string str : dictionary) {
			string abbr = str.length() <= 2 ? str : str[0] + to_string(str.length() - 2) + str[str.length() - 1];
			if (!dicSet.count(str)) {
				dicSet.insert(str);
				abbrSet[abbr]++;
			}
		}
	}

	bool isUnique(string word) {
		string abbr = word.length() <= 2 ? word : word[0] + to_string(word.length() - 2) + word[word.length() - 1];
		return dicSet.count(word) ? abbrSet[abbr] == 1 : abbrSet[abbr] == 0;
	}
};
