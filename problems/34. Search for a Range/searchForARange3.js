/**
   * 34. Search for a Range
   * @param {number[]} nums
   * @param {number} target
   * @return {number[]}
*/
//二分法时间复杂度就是o(lgn),时间上还是比前面两种方法要慢
var searchRange = function(nums, target) {

    let loPos = -1, hiPos = -1;

    searchPos(0, nums.length - 1);

    function searchPos(lo, hi) {
      if (lo > hi) return;

      const mid = parseInt((lo + hi) / 2);

      if (nums[mid] === target) {
        if (loPos === -1 || loPos > mid) loPos = mid;
        if (hiPos === -1 || hiPos < mid) hiPos = mid;
        searchPos(lo, mid - 1);
        searchPos(mid + 1, hi);
      }

      if (nums[mid] > target) {
        searchPos(lo, mid - 1);
      }

      if (nums[mid] < target) {
        searchPos(mid + 1, hi);
      }
    }

    return [loPos, hiPos];
  };