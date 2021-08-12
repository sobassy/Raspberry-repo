import cv2
import numpy as np

import serial

ser = serial.Serial("/dev/cu.usbserial-14130", 9600, timeout=None) # シリアル通信の開始

# vird view settings
HEIGHT = 960
WIDTH = 1280
lane_shape = [(300, 600), (980, 600), (0, 960), (1280, 960)]
top_left, top_right, bottom_left, bottom_right = lane_shape
source = np.float32([top_left, top_right, bottom_right, bottom_left])
destination = np.float32([
                (bottom_left[0], 0),
                (bottom_right[0], 0),
                (bottom_right[0], HEIGHT - 1),
                (bottom_left[0], HEIGHT - 1)
                ])
overhead_transform = cv2.getPerspectiveTransform(source, destination)

capture = cv2.VideoCapture(0)

while True:
    # カメラ読み込み
    ret, frame = capture.read()
    # print(frame.shape)
    cv2.imshow("main1", frame)


    # 範囲抽出
    frame = cv2.warpPerspective(frame, overhead_transform, dsize=(WIDTH, HEIGHT))

    cv2.imshow("main3", frame)

    # 2値変換
    img_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    ret, frame = cv2.threshold(img_gray, 0, 255, cv2.THRESH_OTSU)
    
    # print(frame)
    cv2.imshow("main2", frame)

    # SUM
    vec = np.sum(frame, axis=0)
    vec = (vec - vec.min()) / (vec.max() - vec.min()) # normalize

    indexL = np.arange(639, -1, -1)
    indexR = np.arange(640)

    vecL = vec[:640] * indexL
    vecR = vec[640:] * indexR

    vecL = np.sum(vecL)
    vecR = np.sum(vecR)

    pos = (vecR - vecL) / 50000

    # print(pos)
    if pos < 0.43:
        powerR = 0
        powerL = 150 + 15 * abs(pos - 0.145)
        # print("left")
    else:
        # print("right")
        powerL = 0
        powerR = 150 + 15 * abs(pos - 0.145)

    if powerR > 255:
        powerR = 150
    if powerL > 255:
        powerL = 150

    try:
        motor_levels = f"{int(powerL)},{int(powerR)}\r\n" # 改行コードで終了を伝える
        print(motor_levels)
        ser.write(motor_levels.encode("shift-jis")) # 送信するときはバイト型にする
    except:
        motor_levels = "0,0\r\n" # 改行コードで終了を伝える
        print(motor_levels)
        ser.write(motor_levels.encode("shift-jis")) # 送信するときはバイト型にする


    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

motor_levels = f"0,0\r\n" # 改行コードで終了を伝える
print(motor_levels)
ser.write(motor_levels.encode("shift-jis")) # 送信するときはバイト型にする
capture.release()
cv2.destroyAllWindows()
