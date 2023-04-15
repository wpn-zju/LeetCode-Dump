static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> s;
		int result = 0;
		for (int ptr = 0; ptr < height.size(); ++ptr) {
			while (!s.empty() && height[ptr] > height[s.top()]) {
				int h = height[s.top()];
				s.pop();
				if (!s.empty())
					result += (ptr - s.top() - 1) * (min(height[ptr], height[s.top()]) - h);
			}
			s.push(ptr);
		}
		return result;
	}
};