class Solution {
public:
	bool canTransform(string start, string end) {
		int i = 0;
		int j = 0;
		while (i < start.size() && j < start.size()) {
			while (i < start.size() - 1 && start[i] == 'X')
				i++;
			while (j < start.size() - 1 && end[j] == 'X')
				j++;
			if (start[i] != end[j])
				return false;
			else if (start[i] == 'L')
				if (i < j)
					return false;
                else;
			else if (start[i] == 'R')
				if (i > j)
					return false;
				else;
			else
				return true;
			i++;
			j++;
		}
		return true;
	}
};