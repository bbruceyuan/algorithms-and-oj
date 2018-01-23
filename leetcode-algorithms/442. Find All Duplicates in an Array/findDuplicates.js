/**
 * @param {number[]} nums
 * @return {number[]}
 */

// 思路和原来那个找disappeared number是一样的
var findDuplicates = function(nums) {
    let result = [];
    for(let i = 0; i < nums.length; ++i){
        let current = Math.abs(nums[i]) - 1;
        
        if(nums[current] < 0){
            result.push(current + 1);
        }
        nums[current] = -nums[current];
    }
    return result;
};

