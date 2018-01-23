/**
 * @param {number[]} nums
 * @return {number}
 */
//O(n) S(n);注释写的这种方法其实是不符合要求，空间复杂度超了
var firstMissingPositive = function(nums) {
  	// var hash = {};
  	// nums.forEach(function(item){
  	// 	hash[item] = true;
  	// });
  	// var first = 1;
  	// while(hash[first]){
  	// 	first += 1;
  	// }
  	// return first;
  	nums.forEach(function(item, index, array){
  		var current = item;//当前待处理符号。
  		while(current > 0 && current <= nums.length && nums[current - 1] !== current){
  			var temp = nums[current - 1];//下一个待处理符号
  			// [nums[index], nums[current - 1]] = [nums[current - 1], nums[index]];
  			nums[current - 1] = current;
  			current = temp;
  		}
  	});
  	console.log(nums);
  	for(var i = 0; i < nums.length; i++){
  		if(nums[i] !== i + 1){
  			return i + 1;
  		}
  	}
  	return nums.length + 1;
};
console.log(firstMissingPositive([3,4,-1,1,5]));