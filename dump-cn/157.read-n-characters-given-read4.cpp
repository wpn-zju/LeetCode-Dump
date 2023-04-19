// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
	int read(char* buf, int n) {
		int num = n;
		int count = 0;
		int state = 4;
		while (num > 0 && state > 3) {
			state = read4(buf + count);
			count += state;
			num -= state;
		}
		return min(n, count);
	}
};