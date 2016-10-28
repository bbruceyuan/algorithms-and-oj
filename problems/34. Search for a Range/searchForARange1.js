/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

 //这题思路简直不要太简单，可以直接调用函数。
var searchRange = function(nums, target) {
    var result = [];
    result.push(nums.indexOf(target));
    result.push(nums.lastIndexOf(target));
    return result;
};