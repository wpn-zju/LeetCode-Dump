class Solution {
public:
	int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
		vector<int> data;
		for (int i = 1; i <= sideLength; ++i)
			for (int j = 1; j <= sideLength; ++j)
				data.push_back((width - i + sideLength) / sideLength * ((height - j + sideLength) / sideLength));
		sort(data.begin(), data.end(), greater<int>());
		int result = 0;
		for (int i = 0; i < maxOnes; ++i)
			result += data[i];
		return result;
	}
};