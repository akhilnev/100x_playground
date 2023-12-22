// HOW DO I MAKE A HTTP SERVER I USE EXPRESS - MADE BY SMART PEOPLE

const exp = require("express"); // import express in JS FILE , in node package registry 
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
app.listen(port,function(){
    console.log("Server Started"); // start the server on the port number
});


// TASKS OR USEFUL TASKS : CREATE A HTTP SERVER IN C FROM SCARTCH
// CREATE A HTTP SERVER IN GOLAND USING GUERILLA FRAMEOWKR
// CREATE A HTTP SERVER IN RUST USING activex-web FRAMEWORK

