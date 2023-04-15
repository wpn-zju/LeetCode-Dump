class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
		while (label != 1) {
			result.push_back(label);
			label >>= 1;
		}
		result.push_back(1);
		reverse(result.begin(), result.end());
		for (int i = 0; i < result.size(); ++i)
			if (result.size()%2==1 && i % 2 == 1||result.size()%2==0&&i%2==0)
				result[i] = 3 * pow(2, i) - 1 - result[i];
		return result;
    }
};