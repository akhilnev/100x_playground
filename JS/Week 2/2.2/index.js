// HOW DO I MAKE A HTTP SERVER I USE EXPRESS - MADE BY SMART PEOPLE

// 1. npm init -y // to create a package.json file with all the dependencies we need for nodejs to run our server smoothly
const exp = require("express"); 

const fs = require("fs"); // file system module to read and write files

// 2. import express in JS FILE , in node package registry 
// TO ACTUALLY IMPORT THE SAME WE WILL NEED TO <npm install express> in the terminal to install the package

const port = 3000; // port number we will run our server on

const app = exp(); // create an instance of express like an object of a class

app.get("/",function(req,res){
    res.send("Hello World"); // send hello world to the browser when this API is hit !!
});

app.post("/backend-api/conversations",function(req,res){
    // HERE THE OPEN AI DEV WOULD RUN THE MACHINE LEARRNING MODEL BASED ON THE INPUT AND SEND THE RESPONSE BACK
    res.send("Some output done my the OPEN AI SERVER"); // send hello world to the browser when this API is hit !!
}); // eXAMPLE OF A POST REQUEST


// what does this do ?? it starts the server on the port number
app.listen(port,function(){ console.log("Server started on port number : " + port); });

// ADDITONAL NETWORKING ASSIGNMENTS : WILL MOST PROBABLY GO THRU THE C++ ONE FOR ORDERBOOK PROJECT AND EXPANDING THAT ONCE I THINK OR DESIGN WHAT MODEL I WANT TO WORK WITH THERE 

// TASKS OR USEFUL TASKS : CREATE A HTTP SERVER IN C FROM SCARTCH
// CREATE A HTTP SERVER IN GOLAND USING GUERILLA FRAMEOWKR
// CREATE A HTTP SERVER IN RUST USING activex-web FRAMEWORK

// HANDLING BODY OF A POST REQUEST !!

app.post("/backend-api/conversations",function(req,res){
    // HERE THE OPEN AI DEV WOULD RUN THE MACHINE LEARRNING MODEL BASED ON THE INPUT AND SEND THE RESPONSE BACK

    console.log(req.headers); // to see the headers of the request all can be seen on consol or postman
    console.log(req.body); // why does this not work ?? because we need to install a middleware to handle the body of the request
    // WE WILL BE INTRODUCED TO MIDDLEWARES SOON !!!
    // MIDDLEWARES ARE FUNCTIONS THAT RUN BETWEEN THE REQUEST AND RESPONSE OF THE SERVER
    // THEY ARE USED TO HANDLE THE BODY OF THE REQUEST AND MANY OTHER THINGS
    // THEY ARE LIKE A FILTER BETWEEN THE REQUEST AND RESPONSE OF THE SERVER


    res.send("Some output done By the OPEN AI SERVER I HAVE LOCALLY "); // send hello world to the browser when this API is hit !!
});


// BASICS ARE DONE AND NOW WE WILL WORK ON ADDING DATABASE CONNECTION TO OUR SERVER 
// THEN WORK WITH MIDDLEWEARS TO MAKE BACKEND MORE SECURE AND EFFICIENT
// THEN WORK ON AUTHENTICATION AND AUTHORIZATION
// THEN WORK ON THE FRONTEND OF THE APP ( MOVING AHEAD WITH COMBINING JS WITH HTML AND CSS) -> REACT JS -> INTEGRATING FRONT END AND BACKEND OF THE APPLICATION !!