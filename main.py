
import serial
import keyboard
import time

running = True

def read_buttons(line): //receives the string of binaries representing the keypad
    line = line.split()
    for i in range(16):
        if line[i] == b"1":

def main():
    with serial.Serial('COM8:', 9600, timeout=1) as ser:
        while running:
            line = ser.readline()
            print(line)

if __name__ == '__main__':
    main()
