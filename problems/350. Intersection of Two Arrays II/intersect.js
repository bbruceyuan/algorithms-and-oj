/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */


 /**
  * What if the given array is already sorted? How would you optimize your algorithm?
  * What if nums1's size is small compared to nums2's size? Which algorithm is better?
  * What if elements of nums2 are stored on disk, and the memory is limited 
  * such that you cannot load all elements into the memory at once?
 */
var intersect = function(nums1, nums2) {
    let hash = {};
    let result = [];
    
    nums1.forEach((item, index)=>{
        if (!hash[item]) {
            hash[item] = 1;
        } else {
            hash[item] += 1;
        }
    });
    
    nums2.forEach((item, index) => {
        if (hash[item]) {
            result.push(item);
            hash[item] -= 1;
        }
    });
    
    return result;
};