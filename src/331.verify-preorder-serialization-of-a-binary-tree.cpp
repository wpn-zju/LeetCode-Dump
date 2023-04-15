class Solution {
public:
	bool isValidS(string& in) {
		stack<char> s1;
		for (int i = in.length() - 1; i >= 0; --i) {
			if (in[i] == '#')
				s1.push('#');
			else if (s1.size() > 1)
				s1.pop();
			else
				return false;
		}
		return s1.size() == 1;
	}

	bool isValidSerialization(string preorder) {
		string out = "";
		for (int i = 0; i < preorder.size(); ++i)
			if (preorder[i] == '#')
				out.push_back('#');
			else if (preorder[i] == ',')
				out.push_back(',');
			else if (out.back() != '*')
				out.push_back('*');
		preorder.clear();
		for (char& c : out)
			if (c != ',')
				preorder.push_back(c);
		return isValidS(preorder);
	}
};