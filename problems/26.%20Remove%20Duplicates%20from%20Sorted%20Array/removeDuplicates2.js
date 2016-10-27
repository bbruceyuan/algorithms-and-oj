//利用splice可以删除元素的特点。
var removeDuplicates = function(nums){
	var index = 1;
	while(index < nums.length){
		if(nums[index] === nums[index - 1]){
			nums.splice(index, 1);
		}
		index++;
	}
	return nums.length;
};

var a = removeDuplicates([1,2,2,3,3,3]);
console.log(a);
