/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
	if(n === 0){
		return [];
	}
    var max = n * n,
    	rowBegin = 0,    //行
    	rowEnd = n - 1,
    	colBegin = 0,    //列
    	colEnd = n - 1,
    	result = [],
    	temp;
    //其实可以并不需要把每一个初始化为零，不过这里为了速度更快，就初始化了
    /*
		for(let i = 0; i < n; i++){
			result.push([]);
		}//这样就可以，因为js可以给空数组赋值并且将其他未复制的自动填上undefined.
    */
    for(let i = 0; i < n; i++){
    	temp = [];
    	for(let j = 0; j < n; j++){
    		temp.push(0);
    	}
    	result.push(temp);
    }

    var i = 1;
    while(i <= max && colBegin <= colEnd && rowBegin <= rowEnd){
    	for(let j = colBegin; j <= colEnd; j++){
    		result[rowBegin][j] = i++;
    	}
    	rowBegin++;

    	for(let j = rowBegin; j <= rowEnd; j++){
    		result[j][colEnd] = i++;
    	}
    	colEnd--;

    	if(colEnd >= colBegin){
    		for(let j = colEnd; j >= colBegin; j--){
    			result[rowEnd][j] = i++;
    		}
    	}
    	rowEnd--;

    	if(rowEnd >= rowBegin){
    		for(let j = rowEnd; j >= rowBegin; j--){
    			result[j][colBegin] = i++;
    		}
    	}
    	colBegin++;
    }
    	
   	return result;
};

console.log(generateMatrix(3));