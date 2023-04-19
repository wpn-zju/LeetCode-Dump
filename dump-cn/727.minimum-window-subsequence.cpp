class Solution {
public:
    string minWindow(string& S, string& T) {
        if (S.length() == T.length() && S == T)
	    return S;
	if (T.length() == 1 && S.find(T[0]) != string::npos)
	    return T;
	int start = 0;
	int end = S.length();
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 < S.length()) {
	    if (S[ptr1] == T[ptr2])
		    ++ptr2;
	    if (ptr2 == T.length()) {
		    int right = ptr1;
		    --ptr2;
		    while (ptr2 >= 0) {
		        if (S[ptr1] == T[ptr2])
		            --ptr2;
	            --ptr1;
	        }
		    ++ptr1;
		    if (right - ptr1 + 1 < end - start + 1) {
		        start = ptr1;
		        end = right;
		    }
		    ptr2 = 0;
	    }
	    ++ptr1;
	}
	return end - start == S.length() ? "" : S.substr(start, end - start + 1);
    }
};