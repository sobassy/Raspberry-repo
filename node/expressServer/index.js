const express = require('express')
const app = express()
const port = 3000

var gpio = require('rpi-gpio');

const LED_PIN = 40; // 40番ピン（GPIO40ではない、GPIO21）


// LED ピンをOUT方向に設定
gpio.setup(LED_PIN, gpio.DIR_OUT, () => {

    // API start
    app.get('/', (req, res) => {
        res.send('Welcome to Nogata Education API !!')
    })

    app.get('/led/on', (req, res) => {
        gpio.write(LED_PIN, true);
    })

    app.get('/led/off', (req, res) => {
        gpio.write(LED_PIN, true);
    })
    
    app.listen(port, () => {
        console.log(`Example app listening at http://localhost:${port}`)
    })
});
