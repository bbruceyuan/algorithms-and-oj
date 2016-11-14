/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var sum = 0;
    for(var i = 1; i < prices.length; i++){
        var temp = prices[i] - prices[i - 1];
        if(temp > 0){
            sum += temp;
        }
        //sum += Math.max(prices[i] - prices[i -1], 0);
    }
    return sum;
};