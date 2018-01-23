/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var sum = 0,
        target = nums.length - 1;
        
	//i要小于sum是因为这里要保证必须玩下调，如果不往下跳肯定到不了最后一个
    for(var i = 0; i < nums.length && i <= sum; i++){
        if(sum >= target)return true;
        sum = Math.max(sum, i + nums[i]);
    }
    return false;
};