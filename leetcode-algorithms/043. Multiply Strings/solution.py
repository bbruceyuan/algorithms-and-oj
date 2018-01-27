#!/usr/bin/env python
# Created by Bruce yuan on 18-1-27.


class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # 因为题目说了不会用 0 开头，所以　０　开头一定是　０
        if num1[0] == '0' or num2[0] == '0':
            return '0'
        # 用一个数组来表示结果
        result = [0] * (len(num1) + len(num2))
        cur_pos = len(result) - 1

        for first_str in reversed(num1):
            # 第一个乘数
            int1 = int(first_str)
            tmp_pos = cur_pos
            carry = 0
            for second_str in reversed(num2):
                # 第二个乘数
                int2 = int(second_str)
                tmp_result = int1 * int2
                # 返回进位和当前位置的数字，因为两个数相乘最多等于 81
                result[tmp_pos] += tmp_result
                result[tmp_pos - 1] += result[tmp_pos] // 10
                result[tmp_pos] = result[tmp_pos] % 10
                # print(result)
                tmp_pos -= 1
            cur_pos -= 1
        for index, item in enumerate(result):
            if item != 0:
                pos = index
                break
        return ''.join(str(item) for item in result[pos:])


def main():
    a = Solution()
    result = a.multiply('999', '999')
    print(result)

if __name__ == '__main__':
    main()
