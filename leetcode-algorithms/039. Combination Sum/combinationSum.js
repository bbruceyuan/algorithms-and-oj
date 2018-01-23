/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */

 //这里真是搞了我好久，一开始没有想到递归调用，直接就GG
var ans, res;

function search(index, sum, candidates, target) {
    if(sum === target){
      var temp = ans.map(function(item){
        return item;
      });
      res.push(temp);
      return;
    }
    
    for(var i = index; i < candidates.length; i++){
        if(sum + candidates[i] > target) break;
        ans.push(candidates[i]);
        console.log(ans);
        search(i, sum + candidates[i], candidates, target);
        ans.pop();
    }
}

var combinationSum = function(candidates, target) {
    res = [];
    candidates.sort(function(a, b){
      return a - b;
    });
    for(var i = 0; i < candidates.length; i++){
      ans = [candidates[i]];
      search(i, candidates[i], candidates, target);
    }
    return res;
};
console.log(combinationSum([1,2], 3));