function sum(a,b){
    return a+b;
}

// ARROW FUNCTIONS: IMPLEMENTATION OF THE SAME!!
const s = (a,b) => {
    return a+b;
};

// MAP AND FILTER :

// GIVEN ARRAY GIVE ME BACK AN ARRAY MULTIPLYING EVERY VALUE BY 2 !!

// STD METHOD : MAKE A FOOR LOOP 

// MAP METHOD : MAP TAKES IN ORIGINAL ARRAY AND A CALLBACK TRANSFORMATION FUNCTION AND RETURNS A NEW ARRAY !!
// MAP EXISTS AS A FUNCTION ON THE ARRAY CLASS SO arr.map(transform)

const oldArray = [1,2,3,4,5];   

const newArray = oldArray.map((value) => {
    return value*2;
}); // input. map(transform) // which we store!! -> helps us speed up the process of going thru each index of the array induvidually !!

console.log(newArray);


// FILTERING FUNCTION: EXAMPLE GIVE ME ALL THE EVEN VALUES FROM THE ARRAY !!

function isEven(value){
    return value%2 === 0;
};

const evenArray = newArray.filter(isEven); // same way 

console.log(evenArray);

// right way is just to do define the function anonamously inside the filter function !!




