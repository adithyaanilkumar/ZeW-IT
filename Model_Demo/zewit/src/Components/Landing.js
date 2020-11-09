import React from 'react'
import './landing.css'
import img1 from '../Images/hero-img.png'
import img2 from '../Images/grean_leaf.png'
const Landing = () => {
    return (
        <div className='landing'>
            <span className='Zew-it'>ZeW-IT</span>
            <span className='RTF'>R E T H I N K T H E F U T U R E</span>
            <img className='img1' src={img1} />
            <img className='img2' src={img2} />
        </div>
    )
}

export default Landing
