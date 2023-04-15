class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> s;
		for (string& str : emails) {
			int ptr = 0;
			while (str[ptr] != '@')
				++ptr;
			string tmp = "";
			for (int i = 0; i < ptr; ++i) {
				if (str[i] == '+')
					break;
				if (str[i] == '.')
					continue;
				tmp += str[i];
			}
			tmp += str.substr(ptr);
			s.insert(tmp);
		}
		return s.size();
	}
};