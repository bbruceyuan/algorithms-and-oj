/**
 * @param {number} x
 * @return {number}
 * 只会用二分法，牛顿迭代之类的都忘了
 */
var mySqrt = function(x) {
    if (x === 0) return 0;
    let low = 0,
        high = x;
    
    while (true) {
        let a = ~~((low + high) / 2);// 很烦这种题，其实可以更精确，非要搞成是整数。

        if (a * a > x) {
            high = a - 1;
        } else {
            let b = a + 1;
            if (b * b > x) {
                return a;
            }
            low = a + 1;
        }   
    }
};