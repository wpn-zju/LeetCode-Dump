class Solution {
public:
	int readVersion(string& in, int& startIndex) {
		if (startIndex >= in.length())
			return -1;
		int result = 0;
		while (startIndex < in.size() && in[startIndex] != '.') {
			result *= 10;
			result += in[startIndex] - '0';
			++startIndex;
		}
		return result;
	}

	int compareVersion(string version1, string version2) {
		int ptr1 = -1;
		int ptr2 = -1;
		while (true) {
			int v1 = readVersion(version1, ++ptr1);
			int v2 = readVersion(version2, ++ptr2);
			if (v1 == -1 && v2 == -1)
				return 0;
			if (v1 == -1) {
				if (v2)
					return -1;
				while ((v2 = readVersion(version2, ++ptr2)) == 0);
				return v2 > 0 ? -1 : 0;
			}
			if (v2 == -1) {
				if (v1)
					return 1;
				while ((v1 = readVersion(version1, ++ptr1)) == 0);
				return v1 > 0 ? 1 : 0;
			}
			if (v1 != v2)
				return v1 < v2 ? -1 : 1;
		}
		return 0;
	}
};