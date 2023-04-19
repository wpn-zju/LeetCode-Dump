class Solution {
public:
	unordered_map<char, string> charMap = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits == "")
			return result;
		return getString(digits, 0, digits.length() - 1);
	}

	vector<string> getString(string digits, int start, int end) {
		vector<string> result;
		if (start == end) {
			string digitString = charMap[digits[start]];
			for (int i = 0; i < digitString.length(); ++i) {
				string temp = "";
				temp += digitString[i];
				result.push_back(temp);
			}
		}
		else {
			vector<string> temp = getString(digits, start, end - 1);
			string digitString = charMap[digits[end]];
			for (int i = 0; i < temp.size(); ++i) {
				for (int j = 0; j < digitString.length(); ++j) {
					string temp_2 = "";
					temp_2 = temp[i] + digitString[j];
					result.push_back(temp_2);
				}
			}
		}

		return result;
	}
};