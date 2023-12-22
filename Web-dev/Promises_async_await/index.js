const fs = require('fs');

fs.readFile("a.txt", 'utf8', function(err, data){
  console.log(data);
}); // called 2nd as it takes more time than console.log but less than for loop

console.log("Hello World"); // called first as async function is called and readfile takes more time

for(i = 0 ; i < 100000000 ; i++){
    console.log(i); // called 3rd as it takes more time than readfile
}

// LATENT FLIP . LOUPE HELPED ME TO UNDERSTAND THIS CONCEPT BETTER AND SHOWS US HOW ASYNC FUNCTIONS WORK IN JS 
// IT IS A VERY GOOD WEBSITE TO LEARN JS AND ITS CONCEPTS

// In asynchronous programming, we can have multiple tasks running at the same time.

// REAL USE OF CALLBACKS IS IN ASYNC FUNCTIONS , NOT IN SYNC FUNCTIONS




