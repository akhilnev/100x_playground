import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  let state = {
    count: 0
  }
  // To render a component we need to add curly braces around it
  // Note we are writing XML not HTML so there are subte changes in the syntax part of it 
  // Like calling the dynamic function we see onClickHandler being written as onClick={onClickHandler}
  

  // UPDATING THE STATE VARIABLE 
  function onClickHandler() {
    state.count = state.count + 1 
    // works but is not getting RE-rendered!!!
    // As we need to DEFINE A STATE VARIABLE IN REACT ( AS IT WANTS )
    // Use a SPECIFIC IMPORTED HOOK TO DEFINE A STATE!! 
    setCount(count + 1) // use GIVEN FUNCTION TO CHANGE THE VARIABLE VALUE INSIDE IT!! 
  }

  // DEFINING A STATE VARIABLE IN REACT
  const [count,setCount] = useState(0); // count = 0 ; setCount = function to change count ( Arrat Destructuring )
  
  // MAKING A STATE TO DO APPLICATION! 
  const[todos,setTodos] = useState([
    {
      title: "Learn React",
      description: "Learn React and make a counter app",
      Completed: false
    },
    {
      title: "Learn Gen-AI",
      description: "Learn Gen-AI and make a counter app",
      Completed: false
    }
  ]); // todos = [] ; setTodos = function to change todos ( Array Destructuring )
  return (
    // COMPONENT! 
    <div>
        <CustomButton count={count} setCount={setCount}></CustomButton><br></br><br></br>
        <CustomButton count={count+1} setCount={setCount}/><br></br><br></br>
      <button onClick={addNewTodo}>Add Todo</button>
      {todos.map(function(todo){ 
          // basically a for loop iterating through the todos state variable and induvidually passing each todo to the Todo component and rendering it
          return(
            <Todo title={todo.title} description={todo.description} Completed={todo.Completed}></Todo>
          )
        })}
    </div>
  )

  // MAKING CUSTON COMPONENT RATHER THAN PUTTIN EVERYTHING IN THE MAIN 

  function CustomButton(props){

    function onClickHandler(){
      props.setCount(props.count + 1);
    }

    return(
      <button onClick={onClickHandler}> Counter {props.count}</button>
    )

  }

  function addNewTodo(){
    // update the todos state variable by using setTodos function
    // ...todos expands the current state variable and then we add the new todo to it using the following syntax!! 
    setTodos([...todos,{
      title: "Learn React again ",
      description: "Learn React and make a more complicated counter app",
      Completed: True
    }])
  }

  // Component:

  function Todo(props){
    return(
      <div>
        <h1>{props.title}</h1>
        <p>{props.description}</p>
        <p>{props.Completed}</p>
      </div>
    )
  }

}


export default App
