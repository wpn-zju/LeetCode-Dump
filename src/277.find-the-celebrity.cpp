// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	int findCelebrity(int n) {
		int cel = 0;
		for (int i = 0; i < n; ++i)
			if (knows(cel, i))
				cel = i;
		for (int i = 0; i < n; ++i)
			if (i != cel && knows(cel, i) || !knows(i, cel))
				return -1;
		return cel;
	}
};