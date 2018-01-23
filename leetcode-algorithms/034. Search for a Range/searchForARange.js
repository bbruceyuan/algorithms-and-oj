/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

 //这题思路简直不要太简单，可以直接调用函数。
var searchRange = function(nums, target) {
    var result = [];
    result.push(nums.indexOf(target));
    result.push(nums.lastIndexOf(target));
    return result;
};

// meothod 2
 //自己写一个函数来执行 就好了，前后同时遍历,特别值得一提的是这个方法竟然要比上面那个方法快
 var searchRange2 = function(nums, target) {
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


// method3
//二分法时间复杂度就是o(lgn),时间上还是比前面两种方法要慢
var searchRange3 = function(nums, target) {

    let loPos = -1, hiPos = -1;

    searchPos(0, nums.length - 1);

    function searchPos(lo, hi) {
      if (lo > hi) return;

      const mid = parseInt((lo + hi) / 2);

      if (nums[mid] === target) {
        if (loPos === -1 || loPos > mid) loPos = mid;
        if (hiPos === -1 || hiPos < mid) hiPos = mid;
        searchPos(lo, mid - 1);
        searchPos(mid + 1, hi);
      }

      if (nums[mid] > target) {
        searchPos(lo, mid - 1);
      }

      if (nums[mid] < target) {
        searchPos(mid + 1, hi);
      }
    }

    return [loPos, hiPos];
  };