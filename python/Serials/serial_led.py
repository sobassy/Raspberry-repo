import serial

ser = serial.Serial("COM5", 9600, timeout=None) # シリアル通信の開始
# ポート番号(COM4とか)はWindowsならデバイスマネージャかArduino IDEで確認できます

while True:
    led_level = input("LEDの明るさを入力(0-255 qで終了): ")
    if led_level == "q":
        break
    else:
        led_level += "\r\n" # 改行コードで終了を伝える
        ser.write(led_level.encode("shift-jis")) # 送信するときはバイト型にする

ser.close()