/**
 * @param {number[]} nums
 * @return {number}
 */


// 尽管现在知道了直接遍历要比forEach快好多
// 结果保存在result数组中，从大到小排列
var thirdMax = function(nums) {
  	let result = [];

  	nums.forEach(function(item) {
  		let len = result.length;

  		if (len === 0) {
  			result.push(item);
  		} else if (len === 1) {
  			if (result[0] > item) {
  				result.push(item);
  			} else if (item > result[0]) {
  				result.unshift(item);
  			}
  		} else if (len === 2) {
  			if (item < result[1]) {
  				result.push(item);
  			} else if (item > result[0]) {
  				result.unshift(item);
  			} else if (item < result[0] && item > result[1]){
  				result.splice(1, 0, item);
  			}
  		} else if (len === 3) {
            if (item > result[2] && item != result[1] && item != result[0]) {
                result.pop()
                if(item > result[0]) {
                    result.unshift(item);
                } else if (item < result[1]) {
                    result.push(item);
                } else if (item < result[0] && item > result[1]) {
                    result.splice(1, 0, item);
                }
            }
  		}
  	});

  	return result.length === 3 ? result[2] : result[0];
};


console.log(thirdMax([1,2,2,5,3,5]));

console.log(thirdMax([3, 2, 1]));
console.log(thirdMax([1, 2]));