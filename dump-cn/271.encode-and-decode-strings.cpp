class Codec {
public:
	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string result = "";
		for (string str : strs) {
			result += '[';
			result += to_string(str.length());
			result += ']';
			result += str;
		}
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		int m = s.length();
		int ptr = 0;
		while (ptr != m) {
			if (s[ptr] == '[')
				ptr++;
			int ptrR = ptr;
			while (s[ptrR] != ']')
				ptrR++;
			string len = s.substr(ptr, ptrR - ptr);
			int lenI = stoi(len);
			result.push_back(s.substr(ptrR + 1, lenI));
			ptr = ptrR + lenI + 1;
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));