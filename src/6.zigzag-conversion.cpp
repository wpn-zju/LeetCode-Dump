class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
        
        int charPerBlock = numRows * 2 - 2;
		string result(s.length(), ' ');

		int index1 = 0;
		for (int j = 0; j < numRows; ++j)
		{
			bool flag = true;
			int index2 = j;
			int step1 = charPerBlock - 2 * j;									// 步长1
			if (step1 == 0)
				step1 = charPerBlock;
			int step2 = step1 == charPerBlock ? step1 : charPerBlock - step1;	// 步长2
			while (index2 < s.length())
			{
				result[index1] = s[index2];
				index1++;
				if (flag)
					index2 += step1;
				else
					index2 += step2;
				flag = !flag;
			}
		}

		return result;
	}
};