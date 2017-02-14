/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

var containsNearbyDuplicate = function(nums, k) {
  var pos = [];
  for(var i = 0, len = nums.length; i < len; i++) {
    if (pos[nums[i]] === undefined) 
      pos[nums[i]] = i;
    else {
      if (i - pos[nums[i]] <= k) 
        return true;
      pos[nums[i]] = i;
    }
  }

  return false;
};