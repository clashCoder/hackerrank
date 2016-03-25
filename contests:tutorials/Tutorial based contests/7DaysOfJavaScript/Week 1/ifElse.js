/*Objective: 
print 

AA if marks is greater than 90. 
AB if marks is greater than 80 and less than or equal to 90. 
BB if marks is greater than 70 and less than or equal to 80. 
BC if marks is greater than 60 and less than or equal to 70. 
CC if marks is greater than 50 and less than or equal to 60. 
CD if marks is greater than 40 and less than or equal to 50. 
DD if marks is greater than 30 and less than or equal to 40.  
FF if marks is less than or equal to 30.
*/

//Do not declare variable marks.
//Write your code below this line.

if (marks <= 30) {
    console.log("FF");
}
else if (marks <= 40) {
    console.log("DD");
}
else if (marks <= 50) {
    console.log("CD");
}
else if (marks <= 60) {
    console.log("CC");
}
else if (marks <= 70) {
    console.log("BC");
}
else if (marks <= 80) {
    console.log("BB");
}
else if (marks <= 90) {
    console.log("AB");
}
else {
    console.log("AA");
}
