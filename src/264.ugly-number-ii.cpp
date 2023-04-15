class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[3]{0};
        vector<int> ugly(n, 1);
        for(int i = 1;i<n;++i){
            int a = ugly[arr[0]]*2;
            int b = ugly[arr[1]]*3;
            int c = ugly[arr[2]]*5;
            int next = min(min(a,b),c);
            if(next == a)
                arr[0]++;
            if(next == b)
                arr[1]++;
            if(next == c)
                arr[2]++;
            ugly[i] = next;
        }
        return ugly[n - 1];
    }
};