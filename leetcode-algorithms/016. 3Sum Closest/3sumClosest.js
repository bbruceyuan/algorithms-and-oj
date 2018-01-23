/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 //感觉和前面的3sum思想有点接近。
var threeSumClosest = function(nums, target) {
    var MAX_VLAUE = 2147483647;

    if(nums.length < 3){
    	return 0;
    }
    //先排序一波
    nums.sort(function(a, b){
    	return a - b;
    });

    
    var	minDiff = MAX_VLAUE,
    	nowDiff,
    	p1,
    	p2,
    	complement,
    	sum,
    	result;

    for(var i = 0; i < nums.length - 2; i++){//确保后面还有至少两个数
    	complement = target - nums[i];

    	p1 = i+ 1;
    	p2 = len - 1;
    	while(p1 < p2){
    		sum = nums[p1] + nums[p2];
    		nowDiff = Math.abs(complement - sum);
    		if(minDiff > nowDiff){
    			minDiff = nowDiff;
    			result = sum + nums[i];//有遇到更小的差值的才改变
    		}
    		if(minDiff === 0){
    			break;
    		}
    		if(sum > complement){
    			p2--;
    		}else if(sum < complement){
    			p1++;
    		}
    	}
    	while(nums[i+1] === nums[i]){
    	    i++;//为了做更少的工作，其实这一步只是在减少重复工作。
    	}
    }

    return result;
};

