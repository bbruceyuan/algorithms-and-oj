/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
 
 // 因为不提供新的额外空间，所以这里最好是从后面开始往前遍历
var merge = function(nums1, m, nums2, n) {
   while (m > 0 && n > 0) {
        if (nums1[m - 1] > nums2[n - 1]) {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        } else {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
    while (m > 0) {
    	nums1[m - 1] = nums1[m - 1];
        m--;
    }
    while (n > 0) {
    	nums1[n - 1] = nums2[n - 1];
        n--;
    }
};