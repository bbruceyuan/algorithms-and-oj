/**
 * @param {number[]} nums
 * @return {number[][]}
 */

 //方法一。
var threeSum = function(nums) {
    var hash = {};

    nums.sort(function(a, b){
    	return a - b;
    });

 	nums.forEach(function(item){
 		if(hash[item]){
 			hash[item]++;//有重复而且要知道每个出现了多少次，因为可以一个数字出现两次。甚至三次。
 		}else{
 			hash[item] = 1;
 		}
 	});
 	
 	var result = [],
 		hashSet = {};

 	for(var i = 0; i < nums.length; i++){
 		for(var j = i + 1; j < nums.length; j++){
 			var a = nums[i],
 				b = nums[j],
 				c = 0 - a -b;

 			if(c < b){
 				break;
 			}

 			if(hashSet[a + ',' + b + ',' + c]){
 				continue;
 			}
 			hash[a]--;
 			hash[b]--;//如果出现多次表示还可以继续用这个数字，否则不能用。

 			if(hash[c]){
 				hashSet[a + ',' + b + ',' + c] = true;
 				result.push([a, b, c]);
 			}

 			hash[a]++;
 			hash[b]++;
 		}
 	}

 	return result;
    
};

console.log(threeSum([1,-1,-1,-1,-1,2,2,2,0,0,0]));
