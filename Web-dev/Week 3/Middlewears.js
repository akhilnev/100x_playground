const express = require("express");
const z = require("zod"); // also do <npm install zod> to get the zod library onto local machine!


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

// SAY I WANT TO USE A MIDDLEWEAR IN ALL FUNCTIONS BELOW SOMETHING I WILL WRITEE

app.use(usercheckMiddleware); // this will run the middleware on all routes below it !!

app.use(express.json()); // this is a middleware to handle the body of the request, as we dont know body can be text,HTML,JSON,etc and this function allows us to do direct req.body instead of parsing or figuring out what to parse !!
// USUALLY DONE ON THE TOP^^^



// INPUT VALIDATION - USERS CAN SEND RANDOM SHIT TO BREAK BACKEND AND TRY TO BREAK THE BACKEND BUT THAT NEEDS TO BE REGULATED - MANUAL INDUVIDUAL EDGE CASE HANDLONG OR ZOD LIBRARY FOR INPUT CHECKS CAN BE USED !!


const mySchema = z.array(z.number); // desired type for kidneys check!!

app.post("/health-checkup",function(req,res){
    //kidneys = [1,2,3] - example of a valid input
    const kidneys = req.body.kidneyId;
    const response = mySchema.safeParse(kidneys);
    res.send({response}); // AS SAFE PARSE SENDS A JSON!!
    const kidneyLength = kidneys.length;

    res.send("You have " + kidneyLength + " kidneys !!");
})

const schema = z.object({
    email : z.string().email(), // email checker 
    password: app.string.min(5), // min 5 length 
    kidneyId: z.literal(1).or.literal(2) // exactly 1 or 2
});
// full schema checks for ful req.body in 1 go!!


app.use(function(err,req,res,next){res.status(500).json({msg:"Sorry something is up"})}) // GLOBAL CACHES!! 

app.listen(3000,function(){console.log("Server started !!")});
