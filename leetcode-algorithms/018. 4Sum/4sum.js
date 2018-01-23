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
		hash = {};
		
	var low, high;

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


// method two
/*
为什么这样的时间比原来那个hash做的还要慢。，简直是心态炸了
*/
var fourSum = function(nums, target){
	nums.sort(function(a, b){
		return a - b;
	});

	var i = 0,
		jj = nums.length - 1,
		low,
		high,
		sum,
		result = [];


	while(i < nums.length - 3){
		if(i && nums[i] === nums[i - 1]){
			i ++;
			continue;
		}

		j = nums.length - 1
		while(j < nums.length && j > i + 2){
			if(j < nums.length -1 && nums[j] === nums[j + 1]){
				j--;
				continue;
			}

			[low, high] = [i + 1, j - 1];
			while(low < high){
				sum = nums[i] + nums[j] + nums[low] + nums[high];
				if(sum < target){
					low += 1;
				}else if(sum > target){
					high -= 1;
				}else {
					result.push([nums[i], nums[low], nums[high], nums[j]]);
					while(low < high && nums[low] === nums[low + 1]){
						low += 1;
					}
					while(low < high && nums[high] === nums[high - 1]){
						high -= 1;
					}

					low += 1;
				}
			}

			j -= 1;
		}

		i++;
	}

	return result;
};

console.log(fourSum([1,0,-1,0,-2,2], 0));