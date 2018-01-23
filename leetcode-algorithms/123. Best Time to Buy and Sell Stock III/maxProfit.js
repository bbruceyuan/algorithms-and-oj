/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices){
	if(prices.length === 0)return 0;
	var leftProfit = [];
	var leftProfitMax = 0,
		leftMin = prices[0];
	var temp;
	for(var i = 0; i < prices.length; i++){
		if(prices[i] < leftMin) leftMin = prices[i];
		temp = prices[i] - leftMin;
		if(temp > leftProfitMax)leftProfitMax = temp;
		leftProfit[i] = leftProfitMax;
	}

	var maxProfits = 0,
		rightProfitMax = 0,
		rightMax = prices[prices.length - 1],
		currentProfit;
	for(var i = prices.length - 1; i >= 0; i--){
		if(prices[i] > rightMax) rightMax = prices[i];
		temp = rightMax - prices[i];
		if(temp > rightProfitMax)rightProfitMax = temp;
		currentProfit = rightProfitMax + (i > 0 ?leftProfit[i]:0);
		if(currentProfit > maxProfits)maxProfits = currentProfit;
	}

	return maxProfits;
};

console.log(maxProfit([1,2,3,2,7,2,9]));
