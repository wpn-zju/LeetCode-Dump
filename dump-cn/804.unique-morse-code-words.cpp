class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> s;
		vector<string> key{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		for (string& str : words) {
			string tmp = "";
			for (char& c : str)
				tmp += key[c - 'a'];
			s.insert(tmp);
		}
		return s.size();
	}
};