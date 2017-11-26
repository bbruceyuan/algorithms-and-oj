/*
this function is too slow. We need to have another solution.
*/

function twoSum(nums, target){
	var tmp,
		position,
		a = [];
	for(var i = 0; i < nums.length; i++){
		tmp = target - nums[i];
		position = nums.indexOf(tmp);
		if(position !== i && position !== -1){
		    a.push(i, position);
		    break;
		}
	}
	return a;
}