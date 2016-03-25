//the function adds '1' to the Integer value held by the button with ID 'btn'
function myFunction() {
    var elem = document.getElementById('btn');
    var a = parseInt(elem.innerHTML, 10);
    a = a+1;
    elem.innerHTML = a;
}