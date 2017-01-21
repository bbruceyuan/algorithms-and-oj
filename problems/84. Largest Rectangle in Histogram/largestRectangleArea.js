/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
  heights.push(0);

  var max = 0;

  var stack = [];

  for (var i = 0, len = heights.length; i < len; i++) {
    while (stack.length && heights[i] < heights[stack[stack.length - 1]]) {
      var top = stack.pop();   // 取到最高的那一列

      // 然后找到次高的那一列
      var nextTop = stack.length === 0 ? -1 : stack[stack.length - 1];

      max = Math.max((i - nextTop - 1) * heights[top], max);
    }
    
    stack.push(i);
  }

  return max;
};


console.log(largestRectangleArea([2,4,5,6,2,3]));