class Solution {
public:
	string multiply(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		vector<int> result(num1.length() + num2.length(), 0);
		for (int i = 0; i < num1.length(); ++i) {
			for (int j = 0; j < num2.length(); ++j) {
				result[i + j] += (num2[j] - '0') * (num1[i] - '0');
			}
		}
		for (int i = 0; i < result.size(); ++i) {
			if (result[i] > 9) {
				result[i + 1] += result[i] / 10;
				result[i] = result[i] % 10;
			}
		}
		while (result.size() > 1 && !result.back())
			result.pop_back();
		reverse(result.begin(), result.end());
        string str(result.size(), '0');
        for(int i =0;i<result.size();++i)
            str[i]+=result[i];
		return str;
	}
};