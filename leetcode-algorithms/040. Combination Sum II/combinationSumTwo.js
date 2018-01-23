/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
//一开始用hash = {}来去重，慢了很多。以后尽量少用这个来去重
var ans, 
	res;
var combinationSum2 = function(candidates, target) {
    res = [];
    candidates.sort(function(a, b){
    	return a - b;
    });
    for(var i = 0; i < candidates.length; i++){
    	if(i && candidates[i] === candidates[i -1]) continue;
    	ans = [candidates[i]];
    	search(i + 1, candidates[i], candidates, target);
    }
    return res;
};

function search(index, sum, candidates, target){
	if(sum === target){
		var temp = ans.map(function(item){
			return item;
		});
		res.push(temp);
		return;
	}

	for(var i = index; i < candidates.length; i++){
		if(sum + candidates[i] > target) break;
		if(i > index && candidates[i] === candidates[i - 1]) continue;
		ans.push(candidates[i]);
		search(i + 1, sum + candidates[i], candidates, target);
		ans.pop();
	}
}

console.log(combinationSum2([10, 1, 2, 7, 6, 1, 5],8));
console.log(combinationSum2([2,2,2,2],4));
console.log(combinationSum2([1,1],1));

//hash去重,还有就是leetcode在测试多个test的时候只是调用了函数，所以全局变量不会改变。
//所以hash要在主函数里面初始化。
// var ans, 
// 	res,
// 	hash;
// var combinationSum2 = function(candidates, target) {
//     hash = {};
//     res = [];
//     candidates.sort(function(a, b){
//     	return a - b;
//     });
//     for(var i = 0; i < candidates.length; i++){
//     	//if(i && candidates[i] === candidates[i -1]) continue;
//     	ans = [candidates[i]];
//     	search(i + 1, candidates[i], candidates, target);
//     }
//     return res;
// };

// function search(index, sum, candidates, target){
// 	if(sum === target){
// 		var temp = ans.map(function(item){
// 			return item;
// 		});
// 		if(!hash[temp]){
// 			res.push(temp);
// 			hash[temp] = true;
// 		}
// 		return;
// 	}

// 	for(var i = index; i < candidates.length; i++){
// 		if(sum + candidates[i] > target) break;
// 		ans.push(candidates[i]);
// 		search(i + 1, sum + candidates[i], candidates, target);
// 		ans.pop();
// 	}
// }