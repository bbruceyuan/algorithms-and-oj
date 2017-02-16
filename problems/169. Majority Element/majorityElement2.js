/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    nums.sort((a,b)=>a-b);
    let count = 1;
    let n = Math.floor(nums.length / 2);
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] === nums[i + 1]) {
            count += 1;
        } else {
            if (count > n) {
                return nums[i];
            } 
            count = 1;
        }
    }
    if (count > n) {
        return nums[nums.length - 1];
    }
};