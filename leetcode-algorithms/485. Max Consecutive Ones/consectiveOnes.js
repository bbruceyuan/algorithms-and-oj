/**
 * @param {number[]} nums
 * @return {number}
 */

// 这题就是典型的动态规划问题，每次要求最优

var findMaxConsecutiveOnes = function(nums) {
  	let max = 0,
  		count = 0;
  	nums.forEach(function(item, index, array){
  		if(item === 1){
  			count++;
  		} else{
  			if(count > max){
  				max = count;
  				count = 0;
  			} else {
  				count = 0;
  			}
  		}
  	}); 
  	if(count > max){
  		max = count;
  	} else {
  		count = 0;
  	}
  	return max; 
};

console.log(findMaxConsecutiveOnes([0,0]));