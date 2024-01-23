import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() { 
  // function returning html wtf is this
  // jsx is combination of HTML and JS 
  const [count, setCount] = useState(0) // this is how we define a state-variable in react!!

  return (
    <div >
        <button onClick={function(){setCount
        ((count) => count + 1)}
          }>
          count is {count}
        </button>
      </div>
  )
}

export default App
