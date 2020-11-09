import React, { useState, useRef, useReducer } from "react";
import * as tf from '@tensorflow/tfjs';
import './Pred.css'
import img from '../Images/Untitled.png'
import img1 from '../Images/test-imgs/1.jpg'
import img2 from '../Images/test-imgs/2.jpg'
import img3 from '../Images/test-imgs/3.jpeg'
import img4 from '../Images/test-imgs/4.jpeg'
import img5 from '../Images/test-imgs/5.jpeg'
const machine = {
    initial: "initial",
    states: {
        initial: { on: { next: "loadingModel" } },
        loadingModel: { on: { next: "modelReady" } },
        modelReady: { on: { next: "imageReady" } },
        imageReady: { on: { next: "identifying" }, showImage: true },
        identifying: { on: { next: "complete" } },
        complete: { on: { next: "modelReady" }, showImage: true, showResults: true }
    }
};

function check(props) {
    console.log('props ')
    console.log(props)
    var max = props.reduce((iMax, x, i, arr) => x > arr[iMax] ? i : iMax, 0);
    let s = ['metal', 'cardboard', 'glass', 'plastic', 'paper', 'Trash']
    console.log(s[max])
    return <h1>{s[max]}</h1>
}
const Pred = () => {

    const [results, setResults] = useState([]);
    const [imageURL, setImageURL] = useState(null);
    const [model, setModel] = useState(null);
    const imageRef = useRef();
    const inputRef = useRef();

    const reducer = (state, event) =>
        machine.states[state].on[event] || machine.initial;

    const [appState, dispatch] = useReducer(reducer, machine.initial);
    const next = () => dispatch("next");

    const loadModel = async () => {
        next();
        const model = await tf.loadLayersModel('https://raw.githubusercontent.com/zenio-innovations/ZeW-IT-Hack-CBS/master/models/model/tensorflow.js/model.json');
        setModel(model);
        next();
    };

    const identify = async () => {
        next();
        await tf.tidy(() => {


            // Convert the canvas pixels to a Tensor of the matching shape
            let img = tf.browser.fromPixels(imageRef.current, 3).resizeNearestNeighbor([300, 300]).toFloat().div(255).expandDims();
            console.log(imageRef.current)
            //img = img.reshape([1, 300, 300, 3]);
            //img = tf.cast(img, 'float32');

            // Make and format the predications
            const output = model.predict(img);

            // Save predictions on the component
            const predictions = Array.from(output.dataSync());
            setResults(predictions);
            console.log(predictions)

        });
        //const results = await model.classify(imageRef.current);
        next();
    };

    const reset = async () => {
        setResults([]);
        next();
    };

    const upload = () => inputRef.current.click();

    const handleUpload = event => {
        const { files } = event.target;
        if (files.length > 0) {
            const url = URL.createObjectURL(event.target.files[0]);
            setImageURL(url);
            next();
        }
    };

    const actionButton = {
        initial: { action: loadModel, text: "Load Model" },
        loadingModel: { text: "Loading Model..." },
        modelReady: { action: upload, text: "Upload Image" },
        imageReady: { action: identify, text: "Identify Type of Waste" },
        identifying: { text: "Identifying..." },
        complete: { action: reset, text: "Reset" }
    };

    const { showImage, showResults } = machine.states[appState];

    return (
        <div className='pred' >
            <div className='bin-upload'>
                {showImage && <img className='img' src={imageURL} alt="upload-preview" ref={imageRef} />}
                <input
                    type="file"
                    accept="image/*"
                    capture="camera"
                    onChange={handleUpload}
                    ref={inputRef}
                />
                {showResults && (
                    <ul>
                        {check(results)}
                    </ul>
                )}
                <button onClick={actionButton[appState].action || (() => { })}>
                    {actionButton[appState].text}
                </button>
            </div>
            <img className={`${actionButton[appState].text == 'Load Model' ? 'bin-img' : 'bin-img bin-img2'} `} src={img} />
            <div className='Carcel'>
                <div className='asd'>
                    <a href={img1} download className='car'><img src={img1} className='car' /></a>
                    <a href={img2} download className='car'><img src={img2} className='car' /></a>
                    <a href={img3} download className='car'><img src={img3} className='car' /></a>
                    <a href={img4} download className='car'><img src={img4} className='car' /></a>
                    <a href={img5} download className='car'><img src={img5} className='car' /></a>
                </div>
                <p style={{ color: '#000000' }}>Click on the images to download</p>
            </div>
        </div >
    )
}

export default Pred
