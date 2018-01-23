//这是最先想到的方法，
var removeElement = function(nums, val) {
    var index = nums.indexOf(val);
        
    while(index !== -1){
        nums.splice(index, 1);
        index = nums.indexOf(val);//这种做法每次必须从0开始，因为改变了数组的长度和解构
    }
    return nums.length;
};
console.log(removeElement([1,1,2,3], 3));

// method two
//利用两个指针，这里是指前后,这样只需要遍历一次。
var removeElement = function(nums, val) {
	var start = 0,
		end = nums.length -1;

	while(start <= end){
		if(nums[start] === val){
			[nums[start], nums[end]] = [nums[end], nums[start]]; //我就试下这种解构赋值，感觉没有python的好看啊。
			end -= 1;
		} else{
			start += 1;
		}
	}

	return start;
}
console.log(removeElement([1,1,2,3], 3));