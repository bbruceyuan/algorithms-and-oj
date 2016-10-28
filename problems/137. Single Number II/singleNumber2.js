/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    var a = 0,
        b = 0;
        
    for (var i = 0; i < nums.length; i++){
        // a = (a ^ nums[i]) & ~b;
        // b = (b ^ nums[i]) & ~a;
        
        b = a & (b ^ nums[i]);
        a = b | (a ^ nums[i]);
    }
    
    return a;
};