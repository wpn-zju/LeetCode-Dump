class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		int xStart = INT_MAX;
		int xEnd = INT_MIN;
		int yStart = INT_MAX;
        int yEnd = INT_MIN;
		for (int i = 0; i < image.size(); ++i) {
			int ptr1 = 0;
			while (ptr1 < image[i].size() && image[i][ptr1] == '0')
				++ptr1;
			if (ptr1 == image[i].size())
				continue;
			xStart = min(i, xStart);
			xEnd = max(i, xEnd);
            yStart = min(ptr1, yStart);
			int ptr2 = image[i].size() - 1;
			while (image[i][ptr2] == '0')
				--ptr2;
            yEnd = max(ptr2, yEnd);
		}
		return (xEnd - xStart + 1) * (yEnd - yStart + 1);
	}
};