//这个方法还是很慢，思想很简单，就是链表的操作。
var addTwoNumbers = function(l1, l2) {
    var add = 0,
		ans,
		head;

	while(l1 || l2){
		var a = l1 ? l1.val : 0,
			b = l2 ? l2.val : 0;

		var sum = a + b + add;
		add = ~~(sum / 10);//这里是去除小数地作用。
							//类似于Math.floor(sum / 10);
		var node = new ListNode(sum % 10);
		if(!ans){
			ans = head = node;
		} else {
			head.next = node;
			head = node;
		}

		if (l1){
			l1 = l1.next;
		}
		if (l2){
			l2 = l2.next;
		}

	}

	if(add){
			var node1 = new ListNode(add);
			head.next = node1;
			head =  node1;
		}
	return ans;
	
    
};
