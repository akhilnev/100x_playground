const express = require("express");

const app = express();

app.get("/health-checkup",(req,res)=>{
    // Writing auth without the middlewares !!

    if(req.headers.username=="Akhi" && req.headers.password=="1234" && (req.query.kidneyId==1 || req.query.kidneyId==2)){
        res.status(200).send("You are healthy !!");
    }else{
        res.status(400).send("You are not healthy !!"); // what is 400?? -> bad request !!
    }

});

// HOW DO I CLEAN UP THE SAME WITH FOLLOWING DRY PRINCIPLE = DO NOT REPEAT YOURSELF !!
// MOST EFF WAY IS TO USE THIS THING CALLED MIDDLEWEARS !!
// THESE ARE PRECHECKS WRITTEN SEPERATELY AND THEN USED IN THE ROUTES !!
// EXAMPLE IS BELOW:

function usercheckMiddleware(req,res,next){

    const username = req.headers.username;
    const password = req.headers.password;
    
    if(username=="Akhi" && password=="1234"){
        next(); // this is used to move to the next middleware or the actual route !!
    }else{
        res.status(403).send("You are not authorized !!");
    }


}

function kidneycheckMiddleware(req,res,next){

    const kidneyId = req.query.kidneyId;

    if(kidneyId==1 || kidneyId==2){
        next();
    }else{
        res.status(403).send("You are not healthy !!");
    }

}

app.get("/healthcheckup",usercheckMiddleware,kidneycheckMiddleware,(req,res)=>{
    res.status(200).send("You are healthy !!");
});


app.listen(3000,function(){console.log("Server started !!")});
