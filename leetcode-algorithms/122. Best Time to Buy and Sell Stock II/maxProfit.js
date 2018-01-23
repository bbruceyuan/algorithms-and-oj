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

// method two
//总是先求出当前一小段时间内的最大利润，然后再把每一段最大利润相加
var maxProfit2 = function(prices) {
    var min = prices[0],
    	max = 0,
    	sum = 0,
    	temp;

    for(var i = 1; i < prices.length; i++){
    	temp = prices[i] - min;
    	if(temp > max){
    		max = temp;
    		if(i === prices.length - 1){
    			sum += max;
    		}
    	}else{
    		sum += max;
    		min = prices[i];
    		max = 0;
    	}
    }//end for

    return sum;
};
console.log(maxProfit([]));