var searchInsert = function(nums, target) {
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