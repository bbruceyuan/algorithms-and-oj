/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let pre = strs[0];
    let i = 1;
    
    while (i < strs.length) {
        while (!strs[i].startsWith(pre)) {
            pre = strs[0].substring(0, pre.length - 1);
        }
        
        i++;
    }
    
    return pre === undefined ? '' : pre;
};