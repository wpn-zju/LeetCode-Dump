class Solution {
public:
	int flipLights(int n, int m) {
		switch (n)
		{
		case 0:
			return 0;
		case 1:
			return m == 0 ? 1 : 2;
		case 2:
			return m == 0 ? 1 : m == 1 ? 3 : 4;
		}
		switch (m) {
		case 0:
			return 1;
		case 1:
			return 4;
		case 2:
			return 7;
		}
		return 8;
	}
};