import React from 'react'
import "./App.css";
import {
  BrowserRouter,
  Link,
  Route,
  Switch,
} from 'react-router-dom'
import Landing from './Components/Landing'
import Pred from './Components/Pred'
import Nav from './Components/Nav'
const App = () => {
  return (
    <>
      <Nav />
      <Landing />
      <Pred />
    </>
  );
}

export default App;
