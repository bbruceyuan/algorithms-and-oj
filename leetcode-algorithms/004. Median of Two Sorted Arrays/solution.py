#!/usr/bin/env python
# Created by BBruceyuan on 18-3-2.


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        有点搞笑，就这么简单的算法都beat 100%
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        a = []
        i1 = 0
        i2 = 0
        while i2 < len(nums2) and i1 < len(nums1):
            if nums1[i1] < nums2[i2]:
                a.append(nums1[i1])
                i1 += 1
            else:
                a.append(nums2[i2])
                i2 += 1
        while i1 < len(nums1):
            a.append(nums1[i1])
            i1 += 1
        while i2 < len(nums2):
            a.append(nums2[i2])
            i2 += 1

        # 见了一个新的数组，利用归并排序
        # 下面只需要找到中间的数字就好了
        if len(a) % 2 == 0:
            mid = len(a) // 2
            return (a[mid - 1] + a[mid]) / 2
        else:
            return a[len(a) // 2]
