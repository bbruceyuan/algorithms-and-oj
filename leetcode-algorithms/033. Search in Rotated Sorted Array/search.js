/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 //相当于自己实现了一下indexOf这个函数的简单版。
var search = function(nums, target) {
    // for(var i = 0; i < nums.length; i++){
    //     if(nums[i] === target){
    //         return i;
    //     }
    // }
    
    // return -1;
    return nums.indexOf(target);
};


// mothod two
// /**
//  * @param {number[]} nums
//  * @param {number} target
//  * @return {number}
//  */
//这里的二分法就是快一点。
var search = function(nums, target){
	var i = 0,
		j = nums.length - 1,
		mid;

	while(i <= j){
		mid = i + ~~((j - i) / 2);
		//console.log(mid);
		if(nums[mid] > target){
			if(nums[i] > nums[j] && target <= nums[j] &&nums[mid] >= nums[i]){
				i = mid + 1;//左边全排列
			}else{
				j = mid - 1;
			}
		}else if(nums[mid] < target){
			if(nums[i] > nums[j] && target >= nums[i] && nums[mid] <= nums[i]){
				j = mid - 1;
			}else {
				i = mid + 1;
			}
		}else {
			return mid;
		}
	}

	return -1;
};

console.log(search([5,7,8,9,1,2,3], 45));



/*
#python的写法。
def search(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    return self.binarySearch(0, len(nums)-1, nums, target)
    
def binarySearch(self, begin, end, nums, target):
    if begin > end:
        return -1
    mid = (begin + end)/2
    if nums[mid] == target:
        return mid
    if nums[mid] < nums[end]: # sorted right half
        if target > nums[mid] and target <= nums[end]:
            return self.binarySearch(mid+1, end, nums, target)
        else:
            return self.binarySearch(begin, mid-1, nums, target)
    else: # sorted left half
        if target < nums[mid] and target >= nums[begin]:
            return self.binarySearch(begin, mid-1, nums, target)
        else:
            return self.binarySearch(mid+1, end, nums, target)
*/
