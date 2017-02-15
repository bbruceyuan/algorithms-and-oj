/**
 * @param {number[]} nums
 * @return {number}
 */

var majorityElement = function(nums) {
  let hash = [];
  for(let i = 0, len = nums.length; i < len; i++) {
    if (!hash[nums[i]]) hash[nums[i]] = 1;
    else hash[nums[i]]++;

    if (hash[nums[i]] > len / 2)
      return nums[i];
  }
};