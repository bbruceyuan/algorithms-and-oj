/*
这里用的还是和3sum一个意思。就是先排序，然后前后逼近。
感觉要是有直接去重的set就好了，类似于python一样的。
*/

var fourSum = function(nums, target){
	nums.sort(function(a, b){
		return a - b;
	});

	var	len = nums.length,
		l1 = 0,
		l2,
		sum,
		result = [],
		low,
		high，
		hash = {};

	while(l1 < nums.length - 3){
		l2 = l1 + 1;

		while(l2 < nums.length - 2){
			[low, high] = [l2+1, nums.length-1];

			while(low < high){
				sum = nums[l1] + nums[l2] + nums[low] + nums[high];
				if(sum < target){
					low += 1;
				}else if(sum > target){
					high -= 1;
				}else{
					var str = nums[l1] + "," + nums[l2] + "," + nums[low] + "," + nums[high];
					if(!hash[str]){
						hash[str] = true;
						result.push([nums[l1], nums[l2], nums[low], nums[high]]);
					}
					low += 1;
				}
			}

			l2 += 1;
		}

		l1 += 1;
	}

	return result;
};

console.log(fourSum([1,0,-1,0,-2,2], 0));