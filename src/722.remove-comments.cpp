class Solution {
public:
	vector<string> removeComments(vector<string>& source) {
		vector<string> result;
		bool comment = false;
		string cur = "";
		for (string& str : source) {
			str.push_back('A');
			if (!comment)
				cur.clear();
			bool inComment = false;
			for (int i = 0; i < str.length() - 1; ++i) {
				if (!inComment) {
					if (comment) {
						if (str[i] == '*' && str[i + 1] == '/'){
                            comment = false;
                            ++i;
                        }
					}
					else if (!comment) {
						if (str[i] == '/'&& str[i + 1] == '*') {
							comment = true;
							++i;
						}
						else if (str[i] == '/' && str[i + 1] == '/') {
							inComment = true;
						}
						else
							cur.push_back(str[i]);
					}
				}
			}
			if (!comment && !cur.empty())
				result.push_back(cur);
		}
		return result;
	}
};