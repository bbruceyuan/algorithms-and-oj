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