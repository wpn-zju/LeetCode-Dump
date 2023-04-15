class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char> set1{ 'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P' };
		unordered_set<char> set2{ 'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L' };
		unordered_set<char> set3{ 'z','x','c','v','b','n','m','Z','X','C','V','B','N','M' };
		unsigned int tag = 0;
		vector<string> result;
		for (string& str : words) {
			tag = 0;
			for (char& c : str) {
				if (set1.count(c))
					tag |= 1u << 1;
				else if (set2.count(c))
					tag |= 1u << 2;
				else if (set3.count(c))
					tag |= 1u << 3;
				if ((tag - 1) & tag)
					break;
			}
			if (!((tag - 1) & tag))
				result.push_back(str);
		}
		return result;
	}
};