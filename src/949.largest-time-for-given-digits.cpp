class Solution {
public:
    bool isValid(int a, int b, int c, int d){
        return a * 10 + b >= 0 && a * 10 + b <= 23 && c * 10 + d >= 0 && c * 10 + d <= 59;
    }
    
    int getTime(int a, int b, int c, int d){
        return 600 * a + 60 * b + 10 * c + d;
    }
    
    void dfs(vector<int>& A, int start, int end, int& mxT, string& result) {
		if (start == end) {
            if(isValid(A[0], A[1], A[2], A[3]) && getTime(A[0], A[1], A[2], A[3]) > mxT){
                mxT = getTime(A[0], A[1], A[2], A[3]);
                result = to_string(A[0]) + to_string(A[1]) + ':' + to_string(A[2]) + to_string(A[3]);
            }
			return;
		}
		for (int i = start; i < end; ++i) {
			swap(A[i], A[start]);
			dfs(A, start + 1, end, mxT, result);
			swap(A[i], A[start]);
		}
	}

    string largestTimeFromDigits(vector<int>& A) {
        int mxT = -1;
        string result = "";
        dfs(A, 0, A.size(), mxT, result);        
        return result;
    }
};