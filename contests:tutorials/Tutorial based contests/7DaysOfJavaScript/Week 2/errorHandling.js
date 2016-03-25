//Task
//
//Given a variable named my_string, try reversing the string using my_string.split(``).reverse().join(``) //and then print the reversed string to the console. 
//If the try clause has an error, print the error message to the console. 
//Finally, print the typeof of the my_string variable to the console.
//
//Output Format
//
//The statement to print in the try block is:
//
//Reversed string is : ${my_string}
//The statement to print in the catch block is:
//
//Error : ${err.message}
//The statement to print in the finally block is:
//
//Type of my_string is : ${typeof my_string}
//Sample Input 0
//
//"1234"
//Sample Output 0
//
//Reversed string is : 4321
//Type of my_string is : string
//Sample Input 1
//
//Number(1234)
//Sample Output 1
//
//Error : my_string.split is not a function
//Type of my_string is : number

function processData(my_string) {
    //Enter your code here
    
    try {
        
        console.log(`Reversed string is : ${my_string.split("").reverse().join("")}`);
    } catch (err) {
        console.log(`Error : ${err.message}`);
    } finally {
        console.log(`Type of my_string is : ${typeof my_string}`);
    }
} 


process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(eval(_input));
});
