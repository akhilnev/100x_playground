const express = require("express");
const jwt = require("jsonwebtoken");
const mongoose = require("mongoose");
const jwtPassword = "123456";

mongoose.connect(
  "mongodb+srv://akhilnev:wzNhM4etH8W1ByI9@cluster0.d4pni82.mongodb.net/MyTrialDB?retryWrites=true&w=majority",
  //mongodb+srv://akhilnev:wzNhM4etH8W1ByI9@cluster0.d4pni82.mongodb.net/<ToFillinDBName>?retryWrites=true&w=majority
);

const User = mongoose.model("User", {
  name: String,
  username: String,
  pasword: String,
});

// BELOW IS SAMPLE USER CREATION TO TEST IF WE ARE SENDING THE DATA TO THE DATABASE OR NOT

//const user = new User({ name: "Akhil", username: "akhilnev", password: "123" });

//user.save().then(() => console.log("User created"));


const app = express();
app.use(express.json());

function userExists(username, password) {
  // should check in the database
}


app.post("/signin", async function (req, res) {
  const username = req.body.username;
  const password = req.body.password;

  if (!userExists(username, password)) {
    return res.status(403).json({
      msg: "User doesnt exist in our in memory db",
    });
  }

  var token = jwt.sign({ username: username}, jwtPassword); // encoding the username in the token, which is later decoded to get the username and check 
  return res.json({
    token,
  });
});

app.get("/users", function (req, res) {
  const token = req.headers.authorization;
  try {
    const decoded = jwt.verify(token, jwtPassword);
    const username = decoded.username;
    // return a list of users other than this username from the database
  } catch (err) {
    return res.status(403).json({
      msg: "Invalid token - please log in again",
    });
  }
});

// findone in JS is a promise, so we can use await ( NEED TO OR ELSE IT WILL GIVE ERROR/ WONT WORK AS DESIRED )
// If we dont use await, then it will return a promise and not the actual value
// promist is treated as true thus we always get user exists which is WRONG 

app.post("/signup", async function(req,res){

  const username = req.body.username;
  const password = req.body.password;
  const name = req.body.name;

  const userExists = await User.findOne({username: username});
  if(userExists){
    return res.status(403).json({"message": "User already exists, please login"}); // 403 means forbidden request
  }
  // ideally also send an email to verify the user and if email belongs to the user or not -> not tough w=but will learn later on

  const user = new User({name, username, password}); // this is the user object that will be saved in the database
  user.save();  // this will save the user in the database

  return res.json({
    "message": "User created successfully"
  });

})

app.listen(3000);


