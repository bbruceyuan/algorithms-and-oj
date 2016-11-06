/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 //相当于自己实现了一下indexOf这个函数的简单版。
var search = function(nums, target) {
    // for(var i = 0; i < nums.length; i++){
    //     if(nums[i] === target){
    //         return i;
    //     }
    // }
    
    // return -1;
    return nums.indexOf(target);
};