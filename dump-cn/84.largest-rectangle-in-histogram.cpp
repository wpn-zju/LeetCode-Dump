class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int result = 0;
		height.push_back(0);    // Key Step
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