// Promises is syntactic sugar for callbacks
// Same way we used callbacks to handle async code, we can use promises
// but makes it look better

// CREATE WRAPPER AROUND CALLBACKS

// UGLY WAY OF DOING IT : ( WITHOUT PROMISES )

const fs = require('fs');

// function akhiReadfile(fn){

//     fs.readFile("a.txt", 'utf8', function(err, data){
//         fn(data); // when done , call fn 
//     }); // reads from a.txt and calls fn when done reading with data read 
    
// }

// function fn(data){
//     console.log(data);
// }

// akhiReadfile(fn);  // first call akhireadfile and then call fn when done reading, meaning fn is put on the callback queue while akhireadfile is put on the call stack

// BETTER WAY OF DOING IT : ( WITH PROMISES )

// understanding syntax of promises

function akhiReadfilePromise(){
    console.log("inside akhireadfilepromise");
    return new Promise(function(resolve){
        console.log("inside promise");
        fs.readFile("a.txt", 'utf8', function(err, data){
            console.log("before resolve");
            resolve(data); // when done , call fn 
        }); // reads from a.txt and calls fn when done reading with data read 
    });
}


function OnDone(data){
    console.log(data);
}

akhiReadfilePromise().then(OnDone);

// MORE ON PROMISES CLASS! 

var d = new Promise(function(resolve) {
    setTimeout( function() {
    resolve("fooooo") }, 10000);
}); 




function Done(){
    console.log(d);
}


console.log(d);
d.then(Done());

// first arguement is always function and second is resolving function, may be called direcrly or by using resolve keyword with .then() in the object call !

// 3 STATES OF PROMISES : RESOLVED , REJECTED AND PENDING :
