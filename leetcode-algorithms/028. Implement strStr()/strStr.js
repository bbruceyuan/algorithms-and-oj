/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */

 // 这题主要是自己实现一个indexOf
var strStr = function(haystack, needle) {
    for (let i = 0; ; i++) {
        for (let j = 0; ; j++) {
            if (j === needle.length) return i;
            if (i + j === haystack.length) return -1;
            if (needle.charAt(j) !== haystack.charAt(i + j)) break;
        }
    }
};