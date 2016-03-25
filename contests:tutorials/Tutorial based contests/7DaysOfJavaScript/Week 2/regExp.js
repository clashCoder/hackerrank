//Task
//
//Given a string, s, composed of lowercase letters [a-z], determine if the string begins and ends with the //same vowel.
//
//The code for handling the input and output is given. You only have to declare the re variable. 
//For example, if the regular expression is [aeiou], then write:
//
//var re = /[aeiou]/;
//
//Note: Vowels are a, e, i, o and u.
//
//For example:
//
// Find a substring of length greater than one that starts and ends with same character.
//
//var re = /(.).*\1/;
//
//var str1 = "wxyz";
//var str2 = "wxyzw";
//var str3 = "wxyzx";
//var str4 = "wxywz";
//
//console.log("substring = " + str1.match(re));
//console.log("substring = " + str2.match(re)[0]);
//console.log("substring = " + str3.match(re)[0]);
//console.log("substring = " + str4.match(re)[0]);
//
//The output is:
//
//substring = null
//substring = wxyzw
//substring = xyzx
//substring = wxyw
//
//Constraints
//
//The length of the string is ≥ 3
//
//Sample Input 0
//
//bcd
//
//Sample Output 0
//
//false
//
//Sample Input 1
//
//abcd
//
//Sample Output 1
//
//false
//
//Sample Input 2
//
//abcda
//
//Sample Output 2
//
//true
//
//Sample Input 3
//
//abcdo
//
//Sample Output 3
//
//false
//
//Explanation
//
//bcd: The string starts with a consonant.
//
//abcd: The string starts with the vowel 'a', but doesn't end with a vowel.
//
//abcda: The string starts and ends with the vowel 'a'.
//
//abcdo: The string starts and ends with vowels, but they are not the same vowel.

// declare var re here
// var re = /[aeiou]/;
// var re = new RegExp("[aeiou]");

var re = /(^[a-z]).*\1$/;