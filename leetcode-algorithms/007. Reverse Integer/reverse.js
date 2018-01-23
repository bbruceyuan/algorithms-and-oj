/**
 * @param {number} x
 * @return {number}
 */

 //这里有一个好弱智的地方啊，其实不能用Number.MAX_VALUE来表示是否超过这了这个数的极限数字。
 //还有就是需要知道js的除法是不会自动取整啊。而且最后不要用Math.floor()这个方法，貌似有点慢啊
var reverse = function(x) {
    var MAX = (1 << 30) * 2 - 1;
    var sum = 0;
    while(x !== 0){
        sum = sum * 10 + x % 10;
        x = ~~(x / 10);
    }
    
    return  (Math.abs(sum) > MAX) ? 0 : sum;

};