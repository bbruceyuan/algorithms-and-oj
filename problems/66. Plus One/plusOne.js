/**
 * @param {number[]} digits
 * @return {number[]}
 */
 //下面这个方法要快，是不是只要有判断速度就会变慢啊。

var plusOne = function(digits) {
    // for(var i = digits.length - 1; i >= 0; i--){
    //     if(digits[i] < 9){
    //         digits[i]++;
    //         return digits;
    //     }
    //     digits[i] = 0;
    // }
    // digits.unshift(1);
    // return digits;
    var ans = [],
        add = 0,
        len = digits.length;

    digits[len - 1]++;

    for(var i = len - 1; i >= 0; i--) {
        var sum = digits[i] + add;
        
        ans[i] = sum % 10;
        add = ~~(sum / 10);
  }

  if (add)
    ans.unshift(add);

  return ans;
};

console.log(plusOne([1,2,3,9]));