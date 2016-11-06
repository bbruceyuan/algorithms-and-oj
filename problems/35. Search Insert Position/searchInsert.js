/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 //二分法
var searchInsert = function(nums, target) {
    var low = 0,
    	high = nums.length - 1,
    	mid;

    while(low <= high){
    	mid = low + Math.floor((high - low) / 2);

    	if(target < nums[mid]){
    		if(mid === 0 || ((mid > 0) && nums[mid - 1] < target)){
    			return mid;
    		}
    		high = mid - 1;
    	}else if(target > nums[mid]){
    		low = mid + 1;
    	}else {
    		return mid;
    	}
    }
    return low;
};

console.log(searchInsert([1,2,3], 2.5));