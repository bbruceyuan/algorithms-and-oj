/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var max = nums[0],
    	current = 0;
    for(var i = 0; i < nums.length; i++){
    	if(current > 0){
    		current += nums[i];
    	}else{
    		current = nums[i];
    	}
    	if(current > max){
    		max = current;
    	}
    }
    return max;
};

console.log(maxSubArray([-1,-2,-3]));
