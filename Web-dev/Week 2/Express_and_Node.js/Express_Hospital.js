//BUILDING A DUMMY BACKEND HOSPITAL THROUGH BACKEND ENDPOINTS!!

// OUR LOGIC IS LIKE A DOCTOR LOGIC !!

// CREATING IN MEMORY DATABASE FOR OUR HOSPITAL !!

const express = require("express");

const app = express();

let users = [{name : "John" , kidneys : [{healthy:false},{healthy:true}]}];

app.get("/",function(req,res){
    const johnKidney = users[0].kidneys;
    let healthyKidney = 0;
    for(let i = 0 ; i < johnKidney.length ; i++){
        if(johnKidney[i].healthy){
            healthyKidney++;
        }
    }

    res.json({
        "Healthy Kidneys" : healthyKidney, 
        "Unhealthy Kidneys" : johnKidney.length - healthyKidney,
    });
   
});

app.put("/",function(req,res){

// replace every kidney with a healthy kidney !!

const johnKidney = users[0].kidneys;

for(let i = 0 ; i < johnKidney.length ; i++){
    users[0].kidneys[i].healthy = true;
}

// DONT FORGET TO SEND A RESPONSE !!
res.send("replaced successfully !!");

});

app.use(express.json()); // need to do to access req.body ? 

app.post("/",function(req,res){

    // user can add a new kidney !!!
    // add a new unhealthy kidney to the user !!

    // getting input from bodt

    const isHealthy = req.body.isHealthy; // req.body will not work because we need to install a middleware to handle the body of the request !!

    users[0].kidneys.push({healthy : isHealthy});

    res.send("Kidney added successfully !!");
    
});

app.delete("/",function(req,res){ 
    
    // delete all unhealtgy kidneys of the user !!

    let newKidneyArray = [];

    for(let i = 0 ; i < users[0].kidneys.length ; i++){
        if(users[0].kidneys[i].healthy){
            newKidneyArray.push({healthy : true});
        }
    }

    users[0].kidneys = newKidneyArray;

    res.send("done");
});

app.listen(3000,function(){console.log("Server started on port number : " + 3000)});