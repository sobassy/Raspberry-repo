import serial
import time

ser = serial.Serial("COM5", 9600, timeout=None) # シリアル通信の開始
# ポート番号(COM4とか)はWindowsならデバイスマネージャかArduino IDEで確認できます

while True:
    for x in range(0, 256):
        ser.write((str(x) + "\r\n").encode("shift-jis")) # 送信するときはバイト型にする
    for x in range(255, -1, -1):
        ser.write((str(x) + "\r\n").encode("shift-jis")) # 送信するときはバイト型にする

ser.close()