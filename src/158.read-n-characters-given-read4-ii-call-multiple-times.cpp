// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
	int readPos = 0;
    int writePos = 0;
	char* buff = new char[4];
	int read(char* buf, int n) {
		for(int i = 0; i < n; ++i){
            if (writePos == readPos){
                writePos = read4(buff);
                readPos = 0;
                if (!writePos)
                    return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
	}
};