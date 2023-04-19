class StringIterator {
public:
	string str;
	int index;
	char c;
	int len;
	StringIterator(string compressedString) {
		str = compressedString;
		index = len = 0;
	}

	int getLen() {
		int len = 0;
		while (index < str.length() && str[index] >= '0' && str[index] <= '9') {
			len *= 10;
			len += str[index] - '0';
			index++;
		}
		return len;
	}

	char next() {
        if(!len){
            if(index >= str.length())
                return ' ';
            c=str[index++];
            len = getLen();
        }
		len--;
		return c;
	}

	bool hasNext() {
		return len || index != str.length();
	}
};