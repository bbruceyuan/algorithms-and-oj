/**
 * @param {number[]} nums
 * @return {number[]}
 */

// 思路就是把每一个数放在它本来应该出现的位置上；
// 然后再遍历这个数组就可以找到少了哪几个数字
var findDisappearedNumbers = function(nums) {
	let result = [];
    nums.forEach(function(item, index, array){
    	while(nums[item - 1] != item){
    		let temp = nums[item - 1];
    		nums[item - 1] = item;
    		item = temp;
    	}
    });

    nums.forEach(function(item, index, array){
    	if(array[index] != index + 1){
    		result.push(index + 1);
    	}
    });
    return result;
};

findDisappearedNumbers([4,3,2,7,8,2,3,1]);
