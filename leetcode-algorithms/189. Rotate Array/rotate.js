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

// method two
var rotate2 = function(nums, k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - k - 1);
    reverse(nums, nums.length - k, nums.length - 1);
    reverse(nums, 0, nums.length - 1);
    return nums;
};

function reverse(nums, start, end){
	while(start < end){
		[nums[start], nums[end]] = [nums[end], nums[start]];
		start++;
		end--;
	}
}

// method three
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
var rotate3 = function(nums, k){
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