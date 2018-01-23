/**
- * @param {number[]} nums1
- * @param {number[]} nums2
- * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let hash = {};
    let result = [];
    for (let i = 0; i < nums1.length; i++) {
        if(!hash[nums1[i]]) {
            hash[nums1[i]] = true;
        }
    }
    
    for (let i = 0; i < nums2.length; i++) {
        if (hash[nums2[i]]) {
            result.push(nums2[i]);
            hash[nums2[i]] = false;
        }
    }
    
    return result;
}
console.log(intersection([1,2,3], [1,4,6]));

// es6不过时间感觉要更久
/*
var intersection = function(nums1, nums2) {
    let a = new Set(nums1);
    let b = new Set(nums2);
    let result = new Set([...a].filter(x => b.has(x)));
    return Array.from(result);
};

*/