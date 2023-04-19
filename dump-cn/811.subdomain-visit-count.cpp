class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> result;
		unordered_map<string, int> myMap;
		for (string& str : cpdomains) {
			int times = 0;
			int tag = 0;
			while (str[tag] != ' ') {
				times *= 10;
				times += str[tag] - '0';
				tag++;
			}

			string domain = "";
			int ptr = str.length() - 1;
			while (true) {
				if (ptr < tag)
					break;
				while (ptr > tag && str[ptr] != '.')
					--ptr;
				domain = move(str.substr(ptr + 1));
				myMap[domain] += times;
				ptr--;
			}
		}

		for (auto& a : myMap)
			result.push_back(to_string(a.second) + ' ' + a.first);

		return result;
	}
};