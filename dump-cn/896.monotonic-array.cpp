class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 1)
            return true;
        int ptr = 0;
        while(ptr < A.size() - 1 && A[ptr] == A[ptr + 1])
            ++ptr;
        if(ptr == A.size() - 1)
            return true;
        bool flag = A[ptr] > A[ptr + 1];
        while(ptr < A.size() - 1)
            if(flag && A[ptr] < A[ptr + 1] || !flag && A[ptr] > A[ptr + 1])
                return false;
            else
                ++ptr;
        return true;
    }
};