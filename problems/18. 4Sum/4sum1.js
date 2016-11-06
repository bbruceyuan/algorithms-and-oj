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