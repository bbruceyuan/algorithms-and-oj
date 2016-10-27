
//感觉这种题，自己做完之后应该去看看其他
//大佬得想法。
//方法一
function missingNumber(nums){
    var sum = nums.reduce(function(pre, cur, index, array){
            return pre + cur;
        }),
        sumArray = ((nums.length * (nums.length + 1)) / 2);
    return sumArray - sum;

}
console.log(missingNumber([0,1,3,4]));

//同样是用了线性时间，不过这里等于遍历了两遍，
//所以时间会有一些慢。
//方法二。
var missingNumber2 = function(nums) {
  var hash = [];
  nums.forEach(function(item) {
    hash[item] = true;
  });

  for (var i = 0; ; i++) 
    if (!hash[i]) 
      return i;
};

//方法三，这是一个好想法啊，
//利用xor操作能够两个清零，所以再来一个0-n
//的数组就可以直接放回这样一个数字。
//直接用python写方便一点
/*
def missingNumber(self, nums):
	return reduce(lambda x, y: x xor y, nums + list(range(len(n) + 1));
*/

function missingNumber3(nums){
	var result = nums.length;//这一步一定要有，因为必须
							//有0-nums,length之间全部的数字。
	for(var i = 0; i < nums.length; i++){
		result = i ^ nums[i];
	}
	return result;
}