class Solution {
public:
    int lastRemaining(int n, int m) {
        int last = 0;
        for (std::size_t i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
};