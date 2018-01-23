//这个比较简单，就是比较慢，不知道为啥
var moveZeroes = function(nums) {
    var count = nums.length;
    
    for(var i = 0; i < count; i++){
        if(nums[i] === 0 && i < count){
            nums.push(nums.splice(i, 1)[0]);
            i = i - 1;
            count--;
        }
       
    }
};

var a = [0,0,1];
moveZeroes(a);
console.log(a);
