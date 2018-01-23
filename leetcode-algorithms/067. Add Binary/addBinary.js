/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    a = a.split('').reverse();
    b = b.split('').reverse();

    let res = [];
    let carr = 0;

    for (let i = 0; i < Math.max(a.length, b.length); i++) {
    	let sum = (a[i] === undefined ? 0 : Number(a[i])) + 
    			(b[i] === undefined ? 0 : Number(b[i])) + carr;
    	res[i] = sum & 1;
    	if (sum >= 2) {
    		carr = 1;
    	} else {
    		carr = 0;
    	}
    }

    if (carr) {
    	res[Math.max(a.length, b.length)] = 1;
    }

    return res.reverse().join('');

};
console.log(addBinary('110', '11111'));