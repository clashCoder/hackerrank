// rotates a 3 x 3 grid clockwise (pivot is center of grid or the middle block)
// e.g.
//			1 2 3			becomes				4 1 2
//			4 5 6			-------->			7 5 3
//			7 8 9								8 9 6
//
function myFunction() {
	
	var numBtns = 9;
	
	var grid = [];
	
	for (var j = 1; j < numBtns + 1; j++) {
		var nextBtn = "btn" + j;
		var elem = document.getElementById(nextBtn);
		var out = parseInt(elem.innerHTML, 10);
		grid.push(out);
		//console.log(parseInt(numBtns[i-1], 10));
		//var output = grid[j-1];
		//console.log(output);
	}
	
	for (var i = 1; i < numBtns + 1; i++) {
		
		var btnI = "btn" + i;
		var btnElem = document.getElementById(btnI);
		
		// 2nd button and 3rd button get left element
		if( (i === 2) || (i === 3) ) {
			var leftElem = grid[i-2];
			btnElem.innerHTML = leftElem;
		}
		
		//6th and 9th button get element above them
		if( (i === 6) || (i === 9) ) {
			var upElem = grid[i-4];
			btnElem.innerHTML = upElem;
		}
		
		if( (i === 7) || (i === 8) ) {
			var rightElem = grid[i];
			btnElem.innerHTML = rightElem;
		}
		
		if( (i === 1) || (i === 4) )  {
			var downElem = grid[i+2];
			btnElem.innerHTML = downElem;
		}
	}
	
	//for (var i = 1; i < numBtns + 1; i++) {
		//var nextBtn = "btn" + i;
		//var elem = document.getElementById(nextBtn);
		
	//	if( (i === 1) || (i === 2) ) {
	//		var rightI = i + 1;
	//		var rightBtn = "btn" + rightI; 
	//		var rightElem = document.getElementById(rightBtn);
	//		var rightVal = parseInt(rightElem.innerHTML, 10);
		//	elem.innerHTML = rightVal;
	//	}
		
	//	if( (i === 3 ) || (i === 6) ) {
	//		var belowI = i + 3;
	//		var belowBtn = "btn" + belowI;
	//		var belowElem = document.getElementById(belowBtn);
	//		var belowVal = parseInt(belowElem.innerHTMl, 10);
		//	elem.innerHTML = belowVal;
	//	}
		//var a = parseInt(elem.innerHTML, 10);
		//a = a+1;
		//elem.innerHTML = a;
	//}
	//var nextBtn = "btn" + i;
    //var elem = document.getElementById('btn1');
    //var a = parseInt(elem.innerHTML, 10);
    //a = a+1;
    //elem.innerHTML = a;
}