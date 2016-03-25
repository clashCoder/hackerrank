//Task
//
//Given string s composed of lowercase letters [a-z], print all the vowels together, followed by all the //consonants, in the order that they appear in the string.
//
//The code for handling the input is provided for you in the editor. You have to complete the //vowelsAndConsonants function.
//
//Note: Vowels are a, e, i, o and u.
//
//Sample Input
//
//javascriptloops
//
//Sample Output
//
//a
//a
//i
//o
//o
//j
//v
//s
//c
//r
//p
//t
//l
//p
//s

// complete the function
function vowelsAndConsonants(s) {
    var string = s;
    var sLength = string.length;
    var cons = "";
    var vow = "";
    var vowels = "aeiou"
    
    //separate consonants and vowels to respective string
    for(var i = 0; i < sLength; i++) {
        var character = string.charAt(i);
        //console.log(character);
        var indexFound = vowels.indexOf(character.toLowerCase());
        //console.log(indexFound);
        
        if (indexFound === -1) {
            //cons = cons.concat(character);
            cons += character;
        }
        else {
            vow = vow.concat(character);
        }
    }
    

    //print out vowels    
    for (var j = 0; j < vow.length; j++) {
        console.log(vow.charAt(j));
    }
    
    //print out consonants
    for (var j = 0; j < cons.length; j++) {
        console.log(cons.charAt(j));
    }
}
