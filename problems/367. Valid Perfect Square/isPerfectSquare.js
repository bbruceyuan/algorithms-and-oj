/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    if (num === 1) return true;
    let left = 1, right = Math.floor(num / 2);
    while(left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (mid === num / mid) {
            return true;
        } else if (mid > num / mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return false;
};