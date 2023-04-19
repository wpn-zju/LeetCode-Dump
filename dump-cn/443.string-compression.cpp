class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.size() < 2)
			return chars.size();
		int ptr1 = 0;
		int ptr2 = 0;
		int ptr3 = 0;
		int count = 0;
		while (ptr3 != chars.size()) {
			while (ptr3 != chars.size() && chars[ptr3] == chars[ptr2])
				ptr3++;
			int len = ptr3 - ptr2;
			chars[ptr1] = chars[ptr2];
			ptr1++;
			count++;
			if (len > 1) {
				int log = (int)log10(len);
				while (log >= 0) {
					chars[ptr1] = (len / (int)pow(10,log)) % 10 + '0';
					ptr1++;
					count++;
                    log--;
				}
			}
			ptr2 = ptr3;
		}
		return count;
	}
};