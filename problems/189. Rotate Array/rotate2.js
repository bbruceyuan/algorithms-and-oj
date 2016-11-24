// /**
//  * @param {number[]} nums
//  * @param {number} k
//  * @return {void} Do not return anything, modify nums in-place instead.
//  */
/*
直接看别人的思路
For each element at position i, we need to move them to (i + k) % n, use a buffer to save the element that has been replaced, and move the replaced element to its right place.
We will start from an element, and mark that, if we come back to the starting point, means we need to start over from the element next of the current starting point.
Work terminates when we have move exactly n times.

Example:
Input:
[1,2,3,4,5,6]
2

Process:

startIdx = 0
1, [1,2,3,4,5,6] -> 3, [1,2,1,4,5,6] -> 5, [1,2,1,4,3,6] -> [5,2,1,4,3,6]

startIdx = 1
2, [5,2,1,4,3,6] -> 4, [5,2,1,2,3,6] -> 6, [5,2,1,2,3,4] -> [5,6,1,2,3,4]
*/
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
