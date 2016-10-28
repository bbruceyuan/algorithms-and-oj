/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
 //using recursion to min my code size
var mergeTwoLists = function(l1, l2) {
    var head;
    
    if(l1 === null){
        return l2;
    }
    if(l2 === null){
        return l1;
    }
    if(l1.val <= l2.val){
        head = l1;
        head.next = mergeTwoLists(l1.next, l2);
    }else if(l1.val > l2.val){
        head = l2;
        head.next = mergeTwoLists(l1, l2.next);
    }
    return head;
};

//這個代碼實現要比上面的那個慢好多啊。
var mergeTwoLists1 = function(l1, l2){
    var head;
    if(l1 === null){
        return l2;
    }
    if(l2 === null){
        return l1;
    }

    if(l1.val < l2.val){
        head = l1;
        l1 = l1.next;
    } else {
        head = l2;
        l2 = l2.next;
    }
    var cur = head;
    while(l1 && l2){
        if(l1.val < l2.val){
            cur.next = l1;
            cur = l1;
            l1 = l1.next;
        } else{
            cur.next = l2;
            cur = l2;
            l2 = l2.next;
        }
    }

    if(l1){
        cur.next = l1;
    }
    if(l2){
        cur.next = l2;
    }


    return head;
}