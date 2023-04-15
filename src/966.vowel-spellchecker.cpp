class Solution {
public:
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		vector<string> result;
		unordered_set<char> cons{ 'a','e','i','o','u','A','E','I','O','U' };
		unordered_set<string> wordsMap;
		unordered_map<string, int> myMap1;
		unordered_map<string, int> myMap2;
		for (int i = 0; i < wordlist.size(); ++i) {
			wordsMap.insert(wordlist[i]);
			string s = "";
			for (char& c : wordlist[i])
				if (!cons.count(c))
					if (c > 'Z')
						s.push_back(c);
					else
						s.push_back(c - 'A' + 'a');
				else
					s.push_back('-');
			if (!myMap2.count(s))
				myMap2[s] = i;
			s = "";
			for (char& c : wordlist[i])
				if (c > 'Z')
					s.push_back(c);
				else
					s.push_back(c - 'A' + 'a');
			if (!myMap1.count(s))
				myMap1[s] = i;
		}
		for (string& str : queries) {
			if (wordsMap.count(str))
				result.push_back(str);
			else {
				string s = "";
				for (char& c : str)
					if (c > 'Z')
						s.push_back(c);
					else
						s.push_back(c - 'A' + 'a');
				if (myMap1.count(s)) {
					result.push_back(wordlist[myMap1[s]]);
					continue;
				}
				s = "";
				for (char& c : str)
					if (!cons.count(c))
						if (c > 'Z')
							s.push_back(c);
						else
							s.push_back(c - 'A' + 'a');
					else
						s.push_back('-');
				if (myMap2.count(s))
					result.push_back(wordlist[myMap2[s]]);
				else
					result.push_back("");
			}
		}
		return result;
	}
};