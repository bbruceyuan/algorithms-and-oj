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

// method 2
//这里还是利用了hash的思想，我利用python做这道题也是这样做的。
var twoSum = function(nums, target){
	var hash = {},
        result = [];
    for(var i = 0; i < nums.length; i++){
        hash[nums[i]] = i; 
    }
    for(var j = 0; j< nums.length; j++){
        var a = target - nums[j];
        if(hash[a]){
            result.push(j, hash[a]);
            break;
        }
    }
    return result;
}