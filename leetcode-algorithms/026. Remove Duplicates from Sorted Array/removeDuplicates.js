var removeDuplicates = function(nums) {
    var i = 0;
    for(var j = 1; j < nums.length; j++){
        if(nums[i] !== nums[j]){
            nums[++i] = nums[j]; 
        }
        
    }
    return i+1;
};
console.log(removeDuplicates([1,1,1,2,2,3,3]));

// method two
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
