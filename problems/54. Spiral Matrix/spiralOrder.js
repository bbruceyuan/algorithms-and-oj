/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
	var result = [];
	if(matrix.length === 0)return result;
    var rowEnd = matrix.length - 1,//列的长度
    	colEnd = matrix[0].length - 1,
    	rowBegin = 0,
    	colBegin = 0;

    while(rowBegin <= rowEnd && colBegin <= colEnd){
    	//往又遍历
    	for(let i = colBegin; i <= colEnd; i++){
    		result.push(matrix[rowBegin][i]);
    	}
    	rowBegin++;
    	for(let i = rowBegin; i <= rowEnd; i++){
    		result.push(matrix[i][colEnd]);
    	}
    	colEnd--;
    	if(rowBegin <= rowEnd){
    		for(let i = colEnd; i >= colBegin; i--){
    			result.push(matrix[rowEnd][i]);
    		}
    	}
    	rowEnd--;
    	if(colBegin <= colEnd){
    		for(let i = rowEnd; i >= rowBegin; i--){
    			result.push(matrix[i][colBegin]);
    		}
    	}
    	colBegin++;
    }//end while

    return result;
};

console.log(spiralOrder([[ 1, 2, 3 ],[ 4, 5, 6 ],[ 7, 8, 9 ]]));