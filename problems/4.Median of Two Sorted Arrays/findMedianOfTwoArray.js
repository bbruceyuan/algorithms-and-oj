function findMedian(nums1, nums2){
	var result = [],
		il = 0,
		ir = 0;
	while(il < nums1.length && ir < nums2.length){
		if(nums1[il] < nums2[ir]){
			result.push(nums1[il]);
			il++;
		} else {
			result.push(nums2[ir]);
			ir++;
		}
	}

	while(il < nums1.length){
		result.push(nums1[il]);
		il++;
	}
	while(ir < nums2.length){
		result.push(nums2[ir]);
		ir++;
	}

	if(result.length % 2 === 0){
		var i = (result.length / 2 - 1),
			j = (result.length / 2);
			console.log(i, j);

		return (result[i] + result[j]) / 2;

	} else {
		return result[Math.floor(result.length / 2)];
	}

}

var a = findMedian([1,2,5], [3,4]);
console.log(a);