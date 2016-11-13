/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var profit = 0,
    	current = prices[0];

    for(var i = 1; i < prices.length; i++){
    	if(prices[i] < current){
    		current = prices[i];
    	} else {
    		profit = Math.max(prices[i] - current, profit);
    	}
    }
    return profit;
};

console.log(maxProfit([7, 1, 5, 3, 6, 4]));