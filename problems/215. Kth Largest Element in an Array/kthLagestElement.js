/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

 //注意这里找的是第K大得元素，
 //运用得是快速排序中position得思想。所以就相当于从大到
 //小排序。
var findKthLargest = function(nums, k) {
    var left = 0,
        right = nums.length - 1;
        
    while(true){
        var a = position(nums, left, right);
        
        if(k > a + 1){
            left = a + 1;
        } else if (k < a + 1){
            right = a - 1;
        } else{
            return nums[k - 1];
        }
    }
};

function position(nums, left, right){
    var key = nums[left];
    
    while(left < right){
        while(nums[right] <= key && left < right){
            right--;
        }
        nums[left] = nums[right];
        while(nums[left] >= key && left < right){
            left++;
        }
        nums[right] = nums[left];
    }
    
    nums[left] = key;
    return left;
}