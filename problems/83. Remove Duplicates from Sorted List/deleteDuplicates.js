/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 * 注释部分是我自己想到的方法，后面递归是看的大神的
 * 自己还有另外一个想法，就是把这个链表的所有数字先建一个set
 * 然后等于去重了，然后再根据这个东西新建一个链表。
 * 思路其实和注释一样，只是可以用一些语法糖
 */
var deleteDuplicates = function(head) {
    // let result = [];
    // while(head) {
    //     result.push(new ListNode(head.val));
    //     head = head.next;
    // }
    
    // if (result.length === 0) return head;
    // for (let i = result.length - 1; i >= 1; i--) {
    //     if (result[i].val === result[i - 1].val) {
    //         result.splice(i, 1);
    //     } 
    // }
    
    // for (let i = 0; i < result.length; i++) {
    //     result[i].next = result[i + 1];
    // }
    
    // return result[0];
    
    if (head === null || head.next === null) return head;
    
    head.next = deleteDuplicates(head.next);
    return head.val == head.next.val ? head.next : head;
};