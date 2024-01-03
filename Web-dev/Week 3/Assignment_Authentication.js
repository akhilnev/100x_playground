// IMPORTED JS FILE GIST AND TEMPLATE FOR ASSIGNEMENT WORKING WITH JWT'S (imp authenication concept)
// Assignment: ( Creating simple Authenication Based  application !)
// - 2 Endpoints: 
//     1.POST /sign -in and return JSON with only username ( returns username encrypted token, to not expose any password)
//     2. GET, /users with Headers- Authheader to get list of usernames from backend DB if signed in/ token sent is right!!
//         - Else 403 error should be sent ( Access not allowed )
const express = require("express");
const jwt = require("jsonwebtoken"); // importing webtoken const jwt = require("jasonwebtoken") -> new library!! -> standard jason webtoken 
const jwtPassword = "123456"; // -> password to verify token

const app = express();
app.use(express.json())
// in memory database of username, password and name
const ALL_USERS = [
  {
    username: "harkirat@gmail.com",
    password: "123",
    name: "harkirat singh",
  },
  {
    username: "raman@gmail.com",
    password: "123321",
    name: "Raman singh",
  },
  {
    username: "priya@gmail.com",
    password: "123321",
    name: "Priya kumari",
  },
]; // THESE ARE ALL USED IN LOCAL MEMEORY FOR NOW BUT WE WILL IDEALLY TAKE THEM FROM THE DB !!

function userExists(usern, passw) {
  // Assuming ALL_USERS is an array of objects with 'username' and 'password' properties
  // For example: const ALL_USERS = [{username: 'user1', password: 'pass1'}, {username: 'user2', password: 'pass2'}, ...];

  // Use a for loop to iterate through ALL_USERS
  for (let i = 0; i < ALL_USERS.length; i++) {
    // Check if the current user has the provided username and password
    if (usern === ALL_USERS[i].username && passw === ALL_USERS[i].password) {
      // Return true if the user is found
      return true;
    }
  }

  // Return false if no matching user is found
  return false;
}

app.post("/signin", function (req, res) {
  const username = req.body.username;
  const password = req.body.password;

  if (!userExists(username, password)) {
    return res.status(403).json({
      msg: "User doesnt exist in our in memory db",
    });
  }

  var token = jwt.sign({ username: username }, jwtPassword);
  return res.json({
    token,
  });
});

app.get("/users", function (req, res) {
  const token = req.headers.authorization;
  try {
    const decoded = jwt.verify(token, jwtPassword);
    const username = decoded.username;
    // return a list of users other than this username
    res.json({
      "users": ALL_USERS.filter(function(value){
        if(value.username == username){
          return false;
        }else{
          return true;
        }
      })
    })
  } catch (err) {
    return res.status(403).json({
      msg: "Invalid token",
    });
  }
});

app.listen(3000)