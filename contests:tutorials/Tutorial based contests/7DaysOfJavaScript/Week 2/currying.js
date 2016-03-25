//Task
//
//You are given partially completed code. Your task is to fill in the blanks (_______). 
//Here, pressure is a function that contains nested arrow functions taking single arguments.


function processData(input) {

    "use strict"
    let pressure = (gravity) => (mass) => (height) => gravity * mass * height;  
    let m = input[0];   //m : stores value of mass.
    let g = input[1];   //g : stores value of gravity.
    let h = input[2];   //h : stores value of height.

    let accelerationDueToGravity = pressure(g);//________    //Blank should be replaced by a function which takes a single argument.
    let particleMass = accelerationDueToGravity(m);//________                //Blank should be replaced by a function which takes a single argument.
    let particleHeight = particleMass(h)//________              //Blank should be replaced by a function which takes a single argument.

    let totalPressure = particleHeight;

    console.log(totalPressure);

} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () { 
   processData(_input.split(' ').map(num =>Number(num)));
});
