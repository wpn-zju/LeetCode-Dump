class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> result;
		bool init = false;
		int restore[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (string str : A) {
			if (!init) {
				for (char c : str)
					restore[c - 'a']++;
				init = true;
			}
			else {
				int compare[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
				for (char c : str)
					if (restore[c - 'a'] > 0) {
						restore[c - 'a']--;
						compare[c - 'a']++;
					}
				for (int i = 0; i < 26; ++i)
					restore[i] = compare[i];
			}
		}
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < restore[i]; ++j){
                string tmp = "";
                tmp += ('a'+i);
                result.push_back(tmp);
            }
		return result;
	}
};