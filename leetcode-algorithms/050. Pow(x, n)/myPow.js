/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */

 // 迭代法
var myPow = function(x, n) {
    var isNegative = n < 0 ? (n *= -1, true) : false;

  	var ans = 1;
  	while (n) {
    	(n & 1) && (ans *= x);
    	x *= x;
    	n >>>= 1;  // 无符号右移
  }

  return isNegative ? 1 / ans : ans;
};


// 递归
function myPow2(x, n) {
	if (n === 0) {
		return 1;
	}
	if (n === 1) {
		return x;
	}
	if (n < 0) {
		n = - n;
		x = 1 / x;
	}
	return (n%2===0) ? myPow2(x*x, n/2) : x * myPow2(x, n - 1);
}

