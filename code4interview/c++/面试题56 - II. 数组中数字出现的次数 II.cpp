class Solution {
public:
    unsigned int bitArr[32];
    int singleNumber (vector<int> &nums) {
        // 使用 二进制 字符串来做
        for (const auto &item : nums) {
            updateArr(item);
        }
        int res=0;
        for (int i = 31; i > 0; i--) {
            res += bitArr[i] %3;
            res = res << 1;
        }
        res += bitArr[0] %3;
        return res;
    }

    void updateArr (int x) {
        unsigned int bitMask = 1;
        for (int i = 0; i < 32; i++) {
            bitArr[i] += (bitMask & x) ? 1: 0;
            bitMask  = bitMask << 1;
        }
    }
};