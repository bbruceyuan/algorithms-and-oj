// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {void} Do not return anything, modify nums in-place instead.
//  */

var rotate = function(nums, k){
	var startIndex = 0,
		len = nums.length,
		move = 0,
		idx = 0,
		elem;

	[elem, startIndex] = [nums[idx], idx];
	while(move < len){
		idx = (idx + k) % len;
		[elem, nums[idx]] = [nums[idx], elem];
		move++;

		if(idx === startIndex){
			idx++;
			if(idx >= len)break;
			[elem, startIndex] = [nums[idx], idx];
		}
	}
	console.log(nums);
};
rotate([1,2,3,4,5,6,7],2);