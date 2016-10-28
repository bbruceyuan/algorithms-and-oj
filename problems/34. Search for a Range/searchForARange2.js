/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

 //自己写一个函数来执行 就好了，前后同时遍历,特别值得一提的是这个方法竟然要比上面那个方法快
var searchRange = function(nums, target) {
    var result = [];

	nums.filter(function(item, index, array){
    	if(item === target){
    		result.push(index);
    	}
    });
	if(result.length === 0){
		result.push(-1, -1);
	} else if(result.length === 1){
		result[1] = result[0];
	} else {
		result.splice(1, result.length - 2);
	}

	return result;
};
console.log(searchRange([1,2,5,4,4],6));