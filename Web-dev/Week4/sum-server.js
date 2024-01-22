express = require("express");
const app = express();

app.use((req, res, next) => {
    res.header('Access-Control-Allow-Origin', 'file:///Users/akhileshnevatia/Zerdha_Basic_App/100x_playground/Web-dev/Week4/2box.html'); // Replace with your frontend domain
    res.header('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE');
    res.header('Access-Control-Allow-Headers', 'Content-Type');
    next();
  });

app.get("/sum", function(req,res){
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);
    const sum = a + b;
    res.send("Sum is " + sum);
})

app.listen(3000, function(){
    console.log("Server started on port 3000");
})