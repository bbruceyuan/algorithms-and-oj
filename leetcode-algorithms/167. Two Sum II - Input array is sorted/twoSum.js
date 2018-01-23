/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let i = 0, j = numbers.length - 1;
    let res = numbers[i] + numbers[j];
    while(res !== target) {
        if (res < target) {
            i++;
        } else {
            j--;
        }
        res = numbers[i] + numbers[j];
    }
    return [i+ 1, j + 1];
};
