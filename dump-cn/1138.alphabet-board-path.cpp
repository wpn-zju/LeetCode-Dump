class Solution {
public:
	string alphabetBoardPath(string target) {
		string result = "";
		target = 'a' + target;
		for (char& c : target)
			c -= 'a';
		for (int i = 1; i < target.length(); ++i) {
			if (target[i] == 25) {
				if (target[i - 1] != 25) {
					int div = ('u' - 'a') / 5 - target[i - 1] / 5;
					int mod = ('u' - 'a') % 5 - target[i - 1] % 5;
					if (div > 0)
						for (int i = 0; i < div; ++i)
							result += 'D';
					else if (div < 0)
						for (int i = 0; i > div; --i)
							result += 'U';
					if (mod > 0)
						for (int i = 0; i < mod; ++i)
							result += 'R';
					else if (mod < 0)
						for (int i = 0; i > mod; --i)
							result += 'L';
					result += 'D';
				}
			}
			else if (target[i - 1] == 25) {
				result += 'U';
				int div = target[i] / 5 - ('u' - 'a') / 5;
				int mod = target[i] % 5 - ('u' - 'a') % 5;
				if (div > 0)
					for (int i = 0; i < div; ++i)
						result += 'D';
				else if (div < 0)
					for (int i = 0; i > div; --i)
						result += 'U';
				if (mod > 0)
					for (int i = 0; i < mod; ++i)
						result += 'R';
				else if (mod < 0)
					for (int i = 0; i > mod; --i)
						result += 'L';
			}
			else {
				int div = target[i] / 5 - target[i - 1] / 5;
				int mod = target[i] % 5 - target[i - 1] % 5;
				if (div > 0)
					for (int i = 0; i < div; ++i)
						result += 'D';
				else if (div < 0)
					for (int i = 0; i > div; --i)
						result += 'U';
				if (mod > 0)
					for (int i = 0; i < mod; ++i)
						result += 'R';
				else if (mod < 0)
					for (int i = 0; i > mod; --i)
						result += 'L';
			}
			result += '!';
		}
		return result;
	}
};