from flask import request, Flask, jsonify

app = Flask(__name__)

import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)

p = GPIO.PWM(12, 50)  # channel=12 frequency=50Hz
p.start(0)

@app.route("/")
def hello_world():
    return "welcome to Nogata Education API !!"

@app.route("/led")
def led_pwm():
    led_power = request.args.get('power')
    if led_power:
        p.ChangeDutyCycle(int(led_power))
        return f"set power: {led_power}"
    else:
        return "not changed."


if __name__ == '__main__':
    app.run(debug=True)