// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {void} Do not return anything, modify nums in-place instead.
//  */

var rotate = function(nums, k) {
    k %= nums.length;//这一波操作不能省啊，感觉是因为我英文理解有问题
    var temp = nums.splice(0, nums.length - k);
    Array.prototype.push.apply(nums, temp);
    console.log(nums);
};
rotate([1,2],1);