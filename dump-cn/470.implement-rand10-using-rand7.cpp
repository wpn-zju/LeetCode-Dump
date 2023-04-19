static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int rand10() {
        int r1, r2;
        while((r1 = rand7()) >= 6);
        while((r2 = rand7()) == 7);
        return (r1 << 1) - (r2 & 1);
    }
};