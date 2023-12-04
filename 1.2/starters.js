console.log("hello world");

// object Example 
const val = 
{
    name : " Akhi",
    age : 8
};


// Call Back function example 

console.log(val["name"]);

function printA()
{
    console.log("A");
}   

function printB()
{
    console.log("B");
}

function displayData(callFunction){
    console.log("displayData");
    callFunction();
}

displayData(printA);


setTimeout(printA, 1000); // it will print A after 1 sec ( time out )

//setInterval(printA, 1000); // it will print A after every 1 sec


// Make a terminal clock HH:MM:SS format ( PRETTY EASY WITH SET INTERVAL FORMAT ) 

let h = 0;

let m = 0;

let s = 0;


setInterval(clock, 1000);

function clock()
{
    s++;
    if(s == 60)
    {
        m++;
        s = 0;
    }
    if(m == 60)
    {
        h++;
        m = 0;
    }
    if(h == 24)
    {
        h = 0;
    }
    console.log(h + ":" + m + ":" + s);
}
