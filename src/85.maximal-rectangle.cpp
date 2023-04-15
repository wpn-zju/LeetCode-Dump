class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (!matrix.size())
			return 0;
		vector<int> rectangleArray(matrix[0].size());
		for (int i = 0; i < matrix[0].size(); ++i)
			rectangleArray[i] = matrix[0][i] == '1';
		int result = largestRectangleArea(rectangleArray);
		for (int i = 1; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j)
				rectangleArray[j] = matrix[i][j] == '1' ? rectangleArray[j] + 1 : 0;
			result = max(result, largestRectangleArea(rectangleArray));
		}
		return result;
	}

	int largestRectangleArea(vector<int>& height) {
		int result = 0;
		height.push_back(0);
		vector<int> myStack;
		for (int ptr = 0; ptr < height.size(); ++ptr) {
			while (!myStack.empty() && height[myStack.back()] >= height[ptr]) {
				int h = height[myStack.back()];
				myStack.pop_back();
				int xPos = myStack.size() > 0 ? myStack.back() : -1;
				result = max(result, ((ptr - xPos - 1)*h));
			}
			myStack.push_back(ptr);
		}
		return result;
	}
};