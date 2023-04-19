class Solution {
public:
int shortestSubarray(vector<int>& A, int K) {
    int __counter = 0;
    int sum = 0, begin = 0, res = -1;
    int len = A.size();
    for (int i = 0; i < len; i++) {
        if (A[i] >= K) return 1;
        sum += A[i];
        if (sum < 1) {
            sum = 0;
            begin = i + 1;
            continue;
        }
        for (int j = i - 1; A[j + 1] < 0; j--) {
            A[j] = A[j + 1] + A[j];
            A[j + 1] = 0;
            __counter++;
        }
        if (sum >= K) {
            while (sum - A[begin] >= K || A[begin] <= 0) 
                sum -= A[begin++];
            int length = i - begin + 1;
            if (res < 0 || res > length) 
                res = length;
        }
    }
    return res;
}
};