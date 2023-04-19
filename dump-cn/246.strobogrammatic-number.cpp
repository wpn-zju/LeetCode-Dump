class Solution {
public:
	unordered_map<char, char> searchStro{ { '1','1' }, { '6','9' }, { '8','8' }, { '9','6' }, { '0','0' } };
	bool isStrobogrammatic(string num) {
		for (int i = 0; i < num.size() >> 1; ++i)
			if (searchStro[num[i]] != num[num.size() - i - 1])
				return false;
		return num.size() & 1 ? num[num.size() >> 1] == '0' || num[num.size() >> 1] == '1' || num[num.size() >> 1] == '8' : true;
	}
};