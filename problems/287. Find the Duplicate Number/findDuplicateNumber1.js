/**
 * @param {number[]} nums
 * @return {number}
 */

 //直接利用这个思路，其实和two number sum 这道题的思路是一样的
//不过这里是利用了空间来换取时间上的性能，时间复杂度超了，
//变成了O(n),所以应该算是错的，不过觉得这样的思路好就直接这样写了
var findDuplicate = function(nums) {
    var hash = {};
    for(var i = 0; i < nums.length; i++){
        if(!hash[nums[i]]){
            hash[nums[i]] = true;
        } else{
            return nums[i];
        }
    }
};