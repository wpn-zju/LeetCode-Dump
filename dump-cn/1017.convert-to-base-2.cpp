class Solution {
public:
	string baseNeg2(int N) {
		if (!N)
			return "0";
		vector<int> binary;
		while (N) {
			binary.push_back(N & 1);
			N >>= 1;
		}
		binary.push_back(0);
		binary.push_back(0);
		binary.push_back(0);
		string result = "";
		for (int i = 0; i < binary.size() - 1; ++i)
			if (binary[i] && i & 1)
				++binary[i + 1];
		for (int i = 0; i < binary.size() - 1; ++i) {
			if (binary[i] > 1)
				binary[i + 1] -= binary[i] >> 1;
			else if (binary[i] < 0)
				binary[i + 1] += (-binary[i] >> 1) + 1;
			binary[i] &= 1;
			result.push_back(binary[i] + '0');
		}
		while (result.back() == '0')
			result.pop_back();
		reverse(result.begin(), result.end());
		return result;
	}
};