//1.npm install express
const express = require("express");

// 2 lines we have to write to make doctor clinic and open it to everyone 
const app = express();  

app.listen(port=3000,function(){console.log("Server started on port number : " + port);});

app.get("/",function(req,res){

    res.send("Hello World"); // send hello world to the browser when this API is hit !!

}); // arg1 : route to litsen at , 2 .call back function to give the route request to



function useN(n){
    return n*n; // random function to test the use of middleware
};

app.get("/square",function(req,res){

    const sq = req.query.n; // query is a property of req object which is used to get the query string from the url
    // Parameters can be sent throught query parameters in the url like : http://localhost:3000/square?n=5
    // query string is the string after the ? in the url
    // The second way to send parameters is through the body of the request 

});








