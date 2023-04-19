class Solution {
public:
	int maxLength(vector<string>& arr) {
		vector<uint32_t> bitArr;
		for (string& str : arr) {
			uint32_t tmp = 0;
			for (char& c : str) {
				if (tmp & (1u << c - 'a')) {
					tmp = UINT32_MAX;
					break;
				}
				else
					tmp += 1u << c - 'a';
			}
			if (tmp != UINT32_MAX)
				bitArr.push_back(tmp);
		}
		int result = 0;
		dfsFindStringSeries(bitArr, result, 0, 0);
		return result;
	}

	int bitCountOf(uint32_t& in) {
		int count = 0;
		for (int i = 0; i < 26; ++i)
			count += !!(in & (1 << i));
		return count;
	}

	void dfsFindStringSeries(vector<uint32_t>& bitArr, int& result, uint32_t cur, int index) {
		if (index == bitArr.size()) {
			result = max(result, bitCountOf(cur));
			return;
		}
		dfsFindStringSeries(bitArr, result, cur, index + 1);
		if (!(cur & bitArr[index]))
			dfsFindStringSeries(bitArr, result, cur | bitArr[index], index + 1);
	}
};