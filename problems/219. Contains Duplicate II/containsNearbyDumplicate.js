/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

var containsNearbyDuplicate = function(nums, k) {
    let pos = [];
    for (let i = 0; i < nums.length; i++) {
        if (pos[nums[i]] === undefined) {
            pos[nums[i]] = i;
        } else {
            if (i - pos[nums[i]] <= k) {
                return true;
            }
            pos[nums[i]] = i;
        }
    }
    return false;
};
