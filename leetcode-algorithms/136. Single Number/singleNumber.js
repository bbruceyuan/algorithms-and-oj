/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    var a = 0;
    // for(var i = 0; i < nums.length; i++){
    //     a = a ^ nums[i];
    // }
    // return a;
    nums.forEach(function(item, index, array){
        a ^= array[index];//这样写竟然比 a^=item又速度上的提升
    });
    return a;
};