/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let roman = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1};
    let z = 0;
    for (let i = 0; i < s.length - 1; i++) {
        if (roman[s[i]] < roman[s[i + 1]]) {
            z -= roman[s[i]];
        } else {
            z += roman[s[i]];
        }
    }
    
    return z + roman[s[s.length - 1]];
};