//Task
//
//Write a myFilter function that takes 2 parameters: my_array and callback. 
//Here, my_array is an array of strings and callback is a function that takes the elements of my_array as //its parameter and returns a boolean true if the element is even or false if the element is odd. 
//The myFilter function should return the filtered array.

function myFilter(my_array, callback){
    //Enter your code here
   var arr = [];
   for(var index in my_array) {
       if (callback(my_array[index]) === true) {
           arr.push(my_array[index]);
       }
       //arr.push(callback(my_array[index]) === true);
       //if ( (my_array[index] % 2) === 0 ) {
         //  arr[index] = true
       //}
       //else {
         //  arr[index] = false;
       //}
   }
  
  return arr;
  
}

function processData(inputArray) {
    //In blank write anonymous function, which takes one parameter and returns true if its even or false if its odd.
    console.log(myFilter(inputArray, (x) => (x % 2) === 0 ) ) ;   
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input.split(' ').map(num => Number(num)));
});


