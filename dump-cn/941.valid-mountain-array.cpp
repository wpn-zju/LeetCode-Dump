class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int ptr = 0;
        while(ptr < A.size() - 1 && A[ptr] < A[ptr + 1])
            ++ptr;
        if(ptr == 0 || ptr == A.size() - 1)
            return false;
        while(ptr < A.size() - 1 && A[ptr] > A[ptr + 1])
            ++ptr;
        return ptr == A.size() - 1;
    }
};