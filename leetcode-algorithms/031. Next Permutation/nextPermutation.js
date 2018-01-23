/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    if (nums.lengt === 1) {
        return;
    } 
    let i = nums.length - 2;
    // find first reversed num, 
    for (; i >= 0 ; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        nums.sort((a, b) => a - b);
    } else {
        let j = i + 1,
            ni = nums[i];
        // find first num that bigger than the first reversed num, (start from end)
        for (; j < nums.length; j++) {
            if (nums[j] <= ni) break;
        }
        j--;
        [nums[i], nums[j]] = [nums[j], nums[i]];
        let tempArray = nums.slice(i + 1).sort((a, b) => a - b);
        nums.length = i + 1;
        Array.prototype.push.apply(nums, tempArray);
    }
};