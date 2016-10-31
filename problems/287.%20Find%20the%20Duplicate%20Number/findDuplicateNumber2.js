/**
 * @param {number[]} nums
 * @return {number}
 */

 //循环法，肯定会有一个重复的圈。，只要找到最先重复的那个圈圈。
var findDuplicate = function(nums) {
	//好慢啊，这个比上面那个慢了太多了。
    var slow = 0,
        fast = 0;
        
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow !== fast);
    slow = 0;
    while(true){
        slow = nums[slow];
        fast = nums[fast];
        if(slow === fast){
            return slow;
        }
    }
}

