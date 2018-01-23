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

// method two
var searchInsert2 = function(nums, target) {
	var hash = {};
	nums.forEach(function(item, index, array){
			hash[item] = index;
	});
	
	if(hash[target] !== undefined){
		return hash[target];
	}
	nums[-1] = -Number.MAX_VALUE;
	nums[nums.length] = Number.MAX_VALUE;
	for(var i = 0; i < nums.length; i++){
		if(nums[i - 1] < target && nums[i] > target){
			return i;
		}
	} 
};

console.log(searchInsert([1,2,3], 0));