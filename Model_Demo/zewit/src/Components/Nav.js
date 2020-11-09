import React from 'react'
import './Nav.css'
import img from '../Images/zewit_logo.jpeg'
const Nav = () => {
    return (

        <header className='navbar'>
            <div className='navbar__title navbar__item'><img src={img} /></div>
            <div className='navbar__item aaa bbb'>About Us</div>
            <div className='navbar__item bbb'>Sponsor</div>
            <div className='navbar__item bbb'>Tensorflow Model</div>
        </header>

    )
}

export default Nav
