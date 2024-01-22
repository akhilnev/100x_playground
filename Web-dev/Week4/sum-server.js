const cors = require('cors');
const express = require('express');
const app = express();
app.use(cors());


app.get("/sum", function(req,res){
    const a = parseInt(req.query.a);
    const b = parseInt(req.query.b);
    const sum = a + b;
    res.send("Sum is " + sum);
})

app.listen(3000, function(){
    console.log("Server started on port 3000");
})