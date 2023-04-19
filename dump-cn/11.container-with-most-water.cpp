class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxValue = 0;
		int point1 = 0;
		int point2 = height.size() - 1;
		while (point1 != point2)
		{
			int min = height[point1] > height[point2] ? height[point2] : height[point1];
			int tempValue = (point2 - point1)*min;
			if (tempValue > maxValue)
				maxValue = tempValue;

			if (height[point1] > height[point2])
				point2--;
			else
				point1++;
		}

		return maxValue;
	}
};