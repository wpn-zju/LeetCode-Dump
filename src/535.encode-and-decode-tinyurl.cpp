class Solution {
public:

	unsigned char key[60] = {
		0x02, 0x03, 0x05, 0x07, 0x0b, 0x0d, 0x11, 0x13,
		0x17, 0x1d, 0x1f, 0x25, 0x29, 0x2b, 0x2f, 0x35,
		0x3b, 0x3d, 0x43, 0x47, 0x49, 0x4f, 0x53, 0x59,
		0x61, 0x65, 0x67, 0x6b, 0x6d, 0x71, 0x7f, 0x83,
		0x89, 0x8b, 0x95, 0x97, 0x9d, 0xa3, 0xa7, 0xad,
		0xb3, 0xb5, 0xbf, 0xc1, 0xc5, 0xc7, 0xd3, 0xdf,
		0xe3, 0xe5, 0xe9, 0xef, 0xf1, 0xfb };
    
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		for (int i = 0; i < longUrl.size(); ++i)
			longUrl[i] ^= key[i % 54];
		return longUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		for (int i = 0; i < shortUrl.size(); ++i)
			shortUrl[i] ^= key[i % 54];
		return shortUrl;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));