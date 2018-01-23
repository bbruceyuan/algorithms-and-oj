/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = new Map([
             [')','('],
             ['}', '{'],
             [']', '[']
        ]);
    let res = [];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
            res.push(s[i]);
        } else {
            if (map.get(s[i]) === res[res.length - 1]) {
                res.pop();
            } else {
                return false;
            }
        }
    }
    
    if (res.length !== 0) return false;
    return true;
};