class Solution {
public:
	int readStr(string& input, int& startIndex, bool& file) {
		int p = startIndex;
		while (input[startIndex] != '\n') {
			if (input[startIndex] == '.')
				file = true;
			++startIndex;
		}
		return startIndex - p;
	}

	int lengthLongestPath(string input) {
		int result = 0;
		input += '\n';
		unordered_map<int, int> search;
		int ptr = 0;
		int curLevel = 0;
		while (ptr < input.size() - 1) {
			if (input[ptr] != '\n') {
				bool file = false;
				search[curLevel] = readStr(input, ptr, file);
				if (file) {
					int tmp = 0;
					for (int i = 0; i <= curLevel; ++i)
						tmp += search[i] + 1;
					result = max(result, tmp - 1);
				}
			}
			else {
				int tmp = ++ptr;
				while (input[ptr] == '\t')
					++ptr;
				curLevel = ptr - tmp;
			}
		}
		return result;
	}
};