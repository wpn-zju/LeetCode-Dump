class Solution {
public:
	bool compareArray(int* a, int* b, int size = 26) {
		while (--size)
			if (*(a + size) != *(b + size))
				return false;
		return true;
	}
    
    // 如果范围扩大至Unicode字符集 则使用哈希表代替固定长度的数组
	bool isAnagram(string s, string t) {
		int m = s.length();
		int n = t.length();
		if (m != n)
			return false;
		int sArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int tArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (char c : s)
			sArray[c - 'a']++;
		for (char c : t)
			tArray[c - 'a']++;
		return compareArray(sArray, tArray);
	}
};