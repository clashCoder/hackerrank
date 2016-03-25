//Task
//
//Given a variable named my_height, you must throw errors under the following conditions:
//
//notANumberError - When my_height is NaN.
//hugeHeightError - When my_height is greater than 10.
//tinyHeightError - When my_height is less than 4.
//If you catch one of the errors above, print the error name; otherwise, print my_height.
//
//Sample Input 0
//
//seven
//
//Sample Output 0
//
//notANumberError
//
//Sample Input 1
//
//77
//
//Sample Output 1
//
//hugeHeightError
//
//Sample Input 2
//
//0
//
//Sample Output 2
//
//tinyHeightError
//
//Sample Input 3
//
//8
//
//Sample Output 3
//
//8

function processData(my_height) {
    //Enter your code here
    
    try {
        if(isNaN(my_height)) {
            throw new Error("notANumberError");
        }
        
        if(my_height > 10) {
            throw new Error("hugeHeightError");
        }
        
        if(my_height < 4) {
            throw new Error("tinyHeightError");
        }
        
        console.log(my_height);
        
    } catch (err) {
        console.log(err.message);
    }
} 


process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
